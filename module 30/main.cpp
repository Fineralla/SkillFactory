#include <iostream>
#include "Sort.h"

#if defined(_WIN64) || defined(_WIN32)
#include <io.h>
#include <fcntl.h>
#endif

int main(int argc, const char *argv[])
{
#if defined(_WIN64) || defined(_WIN32)
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
#endif

    long arr_len = 100000000L;
    time_t start, end;
    int seconds;
    int *arr{new int[arr_len]};

    /* Многопоточная */
    printMessage("Многопоточная сортировка: массив " + std::to_string(arr_len) + " элементов.", true);
    std::srand(time(NULL));
    for (long i{0}; i < arr_len; i++)
    {
        arr[i] = std::abs(std::rand()) % 500000;
    }
    Sort::isMultiThreads = true;
    Sort::test_sort(arr, arr_len);
    time(&start);
    Sort::qSort(arr, arr_len);
    time(&end);
    seconds = difftime(end, start);
    Sort::test_sort(arr, arr_len);
    printMessage("Многопоточная сортировка завершена за " + std::to_string(seconds) + " секунд.", true);

    printMessage("\n", true);
    /* Однопоточная */
    printMessage("Однопоточная сортировка: массив " + std::to_string(arr_len) + " элементов.", true);
    std::srand(time(NULL));
    for (long i{0}; i < arr_len; i++)
    {
        arr[i] = std::abs(std::rand()) % 500000;
    }
    Sort::isMultiThreads = false;
    Sort::test_sort(arr, arr_len);
    time(&start);
    Sort::qSort(arr, arr_len);
    time(&end);
    seconds = difftime(end, start);
    Sort::test_sort(arr, arr_len);
    printMessage("Однопоточная сортировка завершена за " + std::to_string(seconds) + " секунд.", true);

    delete[] arr;

#if defined(_WIN64) || defined(_WIN32)
    system("pause");
#endif
    return 0;
}
