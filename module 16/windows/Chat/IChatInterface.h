#pragma once
#include "../DB/DBmessages.h"
#include "../DB/DBusers.h"
#include "../Misc/UserInput.h"
#include "../DB/DBcomplaints.h"
#include "Options.h"
const extern char clear[];

/// @brief Базовый класс интерактивного интерфейса
class IChatInterface
{
protected:
    DBmessages &pubMessagesDB;
    DBmessages &privMessagesDB;
    DBcomplaints &complaintsDB;
    DBusers &usersDB;

    std::shared_ptr<User> AuthorizedUser = nullptr;

public:
    virtual ~IChatInterface() = default;
    IChatInterface(DBmessages &_pubMessagesDB,
                   DBmessages &_privMessagesDB,
                   DBcomplaints &_complaintsDB,
                   DBusers &_usersDB);
    virtual chat::Results run() = 0;
    chat::Results login();

    /// @brief 
    /// @param messages 
    /// @param emptyMsg
    /// @param beforeMsg 
    /// @param start 
    void printMessages(std::vector<std::shared_ptr<Message>> &messages, const std::wstring &&emptyMsg, const std::wstring &&beforeMsg, const uint &start) const;

    /// @brief 
    /// @tparam 
    /// @param t
    /// @param emptyMsg 
    /// @param beforeMsg 
    /// @param start 
    template <typename T>
    void printList(std::vector<std::shared_ptr<T>> &t, const std::wstring &&emptyMsg, const std::wstring &&beforeMsg, const uint &start) const;

    /// @brief 
    /// @param start 
    /// @param perPage 
    /// @param end 
    /// @param mode 
    /// @param max
    /// @return
    chat::Results listNavigation(uint &start, uint &perPage, uint &end, chat::Pagination &mode, uint max);
};

template <typename T>
inline void IChatInterface::printList(std::vector<std::shared_ptr<T>> &t, const std::wstring &&emptyMsg, const std::wstring &&beforeMsg, const uint &start) const
{

    if (t.empty())
    {
        std::wcout << emptyMsg << std::endl;
        return;
    }
    uint k = start;
    for (auto &i : t)
    {
        std::wcout << beforeMsg << L"[" << ++k << L"]" << std::endl;
        i->printData();
    }
}
