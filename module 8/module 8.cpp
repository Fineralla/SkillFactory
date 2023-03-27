#include <iostream>
#include "integerArray.h"
#include <string>

int main(int argc, const char* argv[])
{

    Array<int> arrayOne;
    Array<int> arrayFour;
    Array<char> arrayTwo;
    Array<std::string> arrayThree;

    arrayOne.append(15);
    arrayOne.append(3);
    arrayOne.append(-1);
    arrayOne.append(2);
    arrayOne.append(0);
    arrayOne.append(6);
    arrayOne.append(43);
    arrayOne.append(2);
    arrayOne.append(-6);
    arrayFour.append(15);
    arrayFour.append(3);
    arrayFour.append(-1);
    arrayFour.append(2);
    arrayFour.append(0);
    arrayFour.append(6);
    arrayFour.append(43);
    arrayFour.append(2);
    arrayFour.append(-6);

    if (arrayOne == arrayFour)
    {
        std::cout << "Arrays are equal\n";
    }
    else
    {
        std::cout << "Arrays not equal\n";
    }

    arrayOne.sort();
    arrayOne.printArray();

    arrayTwo.append('a');
    arrayTwo.append('2');
    arrayTwo.append('1');
    arrayTwo.append('b');
    arrayTwo.append('5');
    arrayTwo.append('f');

    arrayThree.append("qwerty");
    arrayThree.append("ABCD");
    arrayThree.append("EFLQ");
    arrayThree.append("POPSA");

    arrayThree.sort();

    arrayThree.printArray();
    arrayOne.inserFirst(999);
    arrayOne.insertAt(3, 545);
    arrayOne.printArray();
    std::cout << "\n";
    arrayTwo.printArray();
    arrayTwo.sort('<');
    std::cout << "\n";
    arrayTwo.printArray();

    if (auto data = arrayOne.getFirstIndexWhere(43))
    {
        std::cout << "����� 43 ������� � �������, ������: " << *data << std::endl;
    }

    if (auto data = arrayTwo.getFirstIndexWhere('b'))
    {
        std::cout << "����� 'b' ������� � �������, ������: " << *data << std::endl;
    }

    if (auto data = arrayThree.getFirstIndexWhere("EFLQ"))
    {
        std::cout << "����� 'EFLQ' ������� � �������, ������: " << *data << std::endl;
    }

    if (auto data = arrayOne.getFirstIndexWhere(45))
    {
        std::cout << "����� 43 ������� � �������, ������: " << *data << std::endl;
    }
    else
    {
        std::cout << "����� 45 �� ������� � �������\n";
    }
    std::cout << "array cout: " << arrayOne.count() << std::endl;



    if (arrayOne == arrayThree)
    {
        std::cout << "Arrays are equal\n";
    }
    else
    {
        std::cout << "Arrays not equal\n";
    }
    arrayThree[2] = "Tree";
    std::cout << arrayOne[2] << "\n";
    std::cout << arrayTwo[2] << "\n";
    std::cout << arrayThree[2] << "\n";
    if (auto value = arrayThree.removeLast()) {
        std::cout << *value << "\n";
    }
    arrayTwo.removeFirst();
    return 0;
}