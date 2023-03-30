#include <iostream>
#include "IArray.h"

int main(int argc, const char* argv[])
{
    integerArray arrayOne;
    integerArray arrayTwo(-5); 

    arrayOne.append(13);
    arrayOne.append(3);
    arrayOne.append(-5);
    arrayOne.append(2);
    arrayOne.append(0);
    arrayOne.append(6);
    arrayOne.append(42);
    arrayOne.append(2);
    arrayOne.append(-6);
    arrayOne.sort();
    arrayOne.printArray();

    arrayTwo.append(11);
    arrayTwo.append(66);

    arrayOne.inserFirst(999);
    // arrayOne.insertAt(10, 122); для несуществующих индексов требуется создавать проверки!
    arrayOne.insertAt(3, 545);

    arrayOne + arrayTwo;
    // arrayOne[10] = 111999; для несуществующих индексов требуется создавать проверки!
    arrayOne.printArray();
    if (auto data = arrayOne.getFirstIndexWhere(66))
    {
        std::cout << "Число 66 найдено, инедкс: " << *data << std::endl;
    }

    if (auto data = arrayOne.getFirstIndexWhere(45))
    {
        std::cout << "Число 45 найдено, инедкс: " << *data << std::endl;
    }
    else
    {
        std::cout << "Число 45 не найдено \n";
    }
    std::cout << "array cout: " << arrayOne.count() << std::endl;
    return 0;
}