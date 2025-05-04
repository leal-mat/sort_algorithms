#include <iostream>
#include "sorting.h"
#include <chrono>
#include <vector>
#include <random>

std::vector<int> generateRandomVector(int size, bool sorted = false)
{
    std::vector<int> arr;
    if (!sorted)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 10000);

        for (int i = 0; i < size; i++)
        {
            arr.push_back(dis(gen));
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            arr.push_back(i);
        }
    }
    return arr;
}

int main()
{
    std::cout << "Sorting Algorithms" << std::endl;
    std::cout << std::endl;

    std::vector<int> arr_select = generateRandomVector(1000, true);
    std::vector<int> arr_quick = generateRandomVector(1000, true);
    std::vector<int> arr_merge = generateRandomVector(1000, true);

    auto start_select = std::chrono::high_resolution_clock::now();
    Sorting::selectionSort(arr_select);
    auto end_select = std::chrono::high_resolution_clock::now();

    // std::cout << "Selection Sort" << std::endl;
    // for (auto n : arr_select)
    // {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;
    auto duration_select = std::chrono::duration_cast<std::chrono::microseconds>(end_select - start_select);
    std::cout << "Selection Sort took " << duration_select.count() << " microseconds" << std::endl;
    std::cout << std::endl;

    auto start_quick = std::chrono::high_resolution_clock::now();
    Sorting::quickSort(arr_quick, 0, arr_quick.size() - 1);
    auto end_quick = std::chrono::high_resolution_clock::now();

    // std::cout << "Quick Sort" << std::endl;
    // for (auto n : arr_quick)
    // {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;
    auto duration_quick = std::chrono::duration_cast<std::chrono::microseconds>(end_quick - start_quick);
    std::cout << "Quick Sort took " << duration_quick.count() << " microseconds" << std::endl;
    std::cout << std::endl;

    auto start_merge = std::chrono::high_resolution_clock::now();
    Sorting::mergeSort(arr_merge, 0, arr_merge.size() - 1);
    auto end_merge = std::chrono::high_resolution_clock::now();

    // std::cout << "Merge Sort" << std::endl;
    // for (auto n : arr_merge)
    // {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    auto duration_merge = std::chrono::duration_cast<std::chrono::microseconds>(end_merge - start_merge);
    std::cout << "Merge Sort took " << duration_merge.count() << " microseconds" << std::endl;
    std::cout << std::endl;
}