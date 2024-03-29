#include "ServerHandler.h"

ServerHandler::ServerHandler(char (&_cmd_buffer)[CMD_BUFFER]) : cmd_buffer(_cmd_buffer)
{
    dbClient.initialise();
    dbClient.DBprovider()->initialize();
}

void ServerHandler::Run()
{
    auto login_size = buffer.getDynDataSize(LOGIN_COUNT);
    if (login_size >= CMD_BUFFER || login_size == 0)
    {
        badRequest();
        return;
    }

    auto page_size = buffer.getDynDataSize(PAGE_TEXT_COUNT);
    if (page_size == 0 || page_size >= CMD_BUFFER)
    {
        badRequest();
        return;
    }

    auto cmd_size = buffer.getDynDataSize(CMD_TEXT_COUNT);
    if (cmd_size == 0 || cmd_size >= CMD_BUFFER)
    {
        badRequest();
        return;
    }

    auto login = buffer.getDynDataS(LOGIN_COUNT);
    auto page_text = buffer.getDynDataS(PAGE_TEXT_COUNT);
    auto cmd_text = buffer.getDynDataS(CMD_TEXT_COUNT);
    auto session_key = buffer.getSessionKey();


    user = dbClient.DBprovider()->getUserByLogin(login);

    if (user != nullptr)
    {
        bool valid_key = user->validateSessionKey(session_key);
        if (!valid_key)
        {
            user = nullptr;
        }
    }
    if (user == nullptr)
    {
        login == "Guest";
        buffer.writeDynData(login, page_text, cmd_text);
    }

    data_buffer_text = "Вы ввели неизвестную команду.\nВведите команду /chat: ";
    buffer.createFlags(sv::get_string);

    if (cmd_text == "/hello")
    {
        data_buffer_text = "Привет, " + login + "! Я сервер, я живой.\nВведите команду: ";
        clearConsole(false);
        return;
    }
    if (cmd_text == "/help")
    {
        std::string admins_commands = user != nullptr && user->isAdmin()
                                          ? "Команда /sv_quit - (admin)завершить работу сервера;\n"
                                          : std::string();
        data_buffer_text =
            "\nКоманды, которые можно вызвать в любое время:\n"

            "Команда /hello - Опрос сервера;\n"
            "Команда /help - Справка;\n"
            "Команда /quit - Закрыть клиент;\n"
            "\n"
            "Команды, которые можно вызвать в любое время авторизованным пользователям:\n"
            "Команда /chat - Общий чат;\n"
            "Команда /private - Личные сообщения;\n"
            "Команда /private:u:userid - Начать личную беседу с пользователем. Поиск по userid;\n"
            "Команда /private:ul:login - Начать личную беседу с пользователем. Поиск по логину;\n"
            "Команда /users - Список пользователей;\n"
            "Команда /profile - Сменить имя логин пароль;\n"
            "Команда /logout - Выйти из чата;\n" +
            admins_commands +
            "\nВведите команду: ";
        clearConsole(false);
        return;
    }

    if (user == nullptr)
    {
        UserAuthPage auth(cmd_buffer, dbClient, user);
        auth.run();
        data_buffer_text = auth.getText();
        return;
    }

    if (cmd_text.compare("/sv_quit") == 0)
    {
        if (user != nullptr && user->isAdmin())
        {
            quit();
            data_buffer_text = "Сервер завершил свою работу.\nВведите команду /quit чтобы завершить работу клиента\nили команду chat когда запустите сервер: ";
        }
        else
        {
            data_buffer_text = "Вы ввели команду доступную только администраторам.\nВведите команду: ";
            clearConsole(false);
        }
        return;
    }

    if (cmd_text == "/logout")
    {
        clearBuffer();
        clearConsole(true);
        data_buffer_text = "Вы вышли из чата. Введите команду /chat: ";
        return;
    }

    if (user->isBanned())
    {
        clearConsole(true);
        data_buffer_text = "Вы заблокированы. Введите команду /logout: ";
        buffer.writeDynData(login, "none", "none");
        return;
    }


    auto cmd = chatMap.check(page_text, cmd_text);

    if (cmd == "/profile")
    {
        UserProfilePage chat(cmd_buffer, dbClient, user);
        chat.run();
        data_buffer_text = chat.getText();
        return;
    }

    if (cmd == "/chat")
    {
        PublicChatPage chat(cmd_buffer, dbClient, user);
        chat.run();
        data_buffer_text = chat.getText();
        return;
    }

    if (cmd == "/users")
    {
        UserListPage chat(cmd_buffer, dbClient, user);
        chat.run();
        data_buffer_text = chat.getText();
        return;
    }

    if (cmd == "/private")
    {
        PrivateChatPage chat(cmd_buffer, dbClient, user);
        chat.run();
        data_buffer_text = chat.getText();
        return;
    }

    data_buffer_text = "Не найдена страница для вашей команды.\nВведите команду /help: ";
    buffer.createFlags(sv::get_string);
    clearConsole(false);
    return;
}

void ServerHandler::badRequest()
{
    data_buffer_text = "Сообщение от сервера: Что-то пошло не так. На сервер пришли данные неверной длинны.";
    clearBuffer();
}

bool ServerHandler::getWork()
{
    return work;
}

void ServerHandler::quit()
{
    work = false;
}

void ServerHandler::clearConsole(bool status)
{
    if (status)
    {
        buffer.addFlags(sv::clear_console);
    }
    else
    {
        buffer.removeFlag(sv::clear_console);
    }
}

void ServerHandler::clearBuffer()
{

    user->setSessionKey(0);
    buffer.setSessionKey(0);
    buffer.createFlags(sv::get_string);
    buffer.setPaginationMode(sv::last_page);
    buffer.setPgPerPage(10);
    buffer.setPgStart(1);
    buffer.setUserInputCount(1000);
    
    buffer.writeDynData("Guest", "none", "none");
}

std::string &ServerHandler::getDataText()
{
    if (dbClient.DBprovider()->getDBerrno())
    {
        dbClient.DBprovider()->DBclose();
        data_buffer_text = "На сервере проблемы с базой данных. Обратитесь к администратору.\nВведите команду /hello для обновления подключения: ";
        dbClient.DBprovider()->clearDBerrno();
        dbClient.DBprovider()->initialize();
    }
    return data_buffer_text;
}

void ServerHandler::onDBerror()
{
    data_buffer_text = "На сервере проблемы с базой данных. Обратитесь к администратору.\n";
    buffer.createFlags(sv::get_string);
}
