#pragma once

#include <iostream>
#include <optional>
#include "BadAnswer.h"
#include <optional>

class integerArray
{
    int _size{ 0 };
    int* _array = nullptr;
    bool _isEmpty{ true };
    int _returnValue{ 0 };

    // private method
    void erase();
    integerArray sort(integerArray arr);

public:
    integerArray() = default;
    integerArray(int size);
    integerArray(const integerArray& array); //  Copy construction
    ~integerArray();
    int count() const;
    bool isEmpty() const;
    void append(int number);             // append an element to end of the array
    void insertAt(int index, int value); // Inserts an element into an array by index
    std::optional<int> first() const;    // return first element from array
    std::optional<int> last() const;     // return last element from array
    std::optional<int> removeFirst();    // Removes the first element from the array and returns it
    std::optional<int> removeLast();
    std::optional<int> removeAt(const int index);
    std::optional<int> getFirstIndexWhere(int value);     // Array search by value
    void inserFirst(int value);                           // Adding an element to the beginning of the array
    void printArray() const;                              // принт array
    void sort(char operation = '>');                      // sort method
    integerArray filter(char operation, int value) const; // Method for filtering an array
    int& operator[](const int index);
    integerArray operator+(integerArray& array);
    integerArray operator+(integerArray&& array);
    integerArray& operator=(const integerArray& array);
    bool operator==(const integerArray& array);
};
