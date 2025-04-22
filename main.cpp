#include <iostream>
#include "sorting_algorithms/sorting.h"

int main()
{
    std::cout << "Sorting Algorithms" << std::endl;
    return 0;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Selection Sort" << std::endl;
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    Sorting::selectionSort(arr);
}