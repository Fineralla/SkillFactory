#include "Chat/ChatRun.h"
#include <io.h>
#include <fcntl.h>
typedef unsigned int uint;

// команда для очистки консоли
const char clear[]{"cls"};

int main(int argc, const char *argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    ChatRun chat;
    chat.Run();
}