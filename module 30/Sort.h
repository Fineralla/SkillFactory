#pragma once
#include <iostream>
#include <future>
#include <thread>
#include <mutex>
#include "ThreadPool.h"
#include "Misc.h"

class Sort
{
private:
    Sort() = default;
    static ThreadPool thPool;

public:
    ~Sort() = default;
    static bool isMultiThreads;
    static void qSort(int *arr, long size);

private:
    static void quicksort(int *array, long left, long right);

public:
    static void test_sort(int *arr, long size);
};
