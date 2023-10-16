#include "Misc.h"

void printMessage(const std::string &&msg, bool endl)
{
#if defined(_WIN64) || defined(_WIN32)
    std::wstring wmesg = std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.from_bytes(msg.data());
    std::wcout << wmesg;
    if (endl)
        std::wcout << std::endl;
#else
    std::cout << msg;
    if (endl)
        std::cout << std::endl;
#endif
}
