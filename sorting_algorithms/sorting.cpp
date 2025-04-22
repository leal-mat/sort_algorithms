#include "sorting_algorithms/sorting.h"
#include <algorithm>
#include <iostream>

std::vector<int> Sorting::selectionSort(std::vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        int minIndex = i;
        for (int j = i; j < n; j++)
        {
            arr[j] < arr[minIndex] ? minIndex = j : minIndex;
        }
        std::swap(arr[i], arr[minIndex]);
    }

    for (auto n : arr)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return arr;
}