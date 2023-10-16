#pragma once
#include <iostream>
#include <string>
#include <codecvt>
#include <locale>
typedef unsigned int uint;

/// @brief Выводит сообщение в консоль. Кроссплатформенная.
/// @param msg Текст сообщения
/// @param endl true - добавить перевод строки
void printMessage(const std::string &&msg, bool endl = true);
