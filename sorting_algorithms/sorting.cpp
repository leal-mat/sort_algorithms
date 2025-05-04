#include "sorting.h"
#include <algorithm>
#include <iostream>

std::vector<int> Sorting::selectionSort(std::vector<int> &arr)
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
    return arr;
}

int medianOfThree(std::vector<int> &arr, int low, int high)
{
    int mid = (low + high) / 2;
    int pivotIndex = 0;
    if (arr.at(low) < arr.at(mid))
    {
        arr.at(mid) < arr.at(high) ? pivotIndex = mid : pivotIndex = high;
    }
    else
    {
        arr.at(low) < arr.at(high) ? pivotIndex = low : pivotIndex = high;
    }
    std::swap(arr.at(pivotIndex), arr.at(high));
    return pivotIndex;
}

int partition(std::vector<int> &arr, int low, int high)
{
    int pivotIndex = medianOfThree(arr, low, high);

    auto pivot = arr.at(pivotIndex);
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr.at(j) < pivot)
        {
            i++;
            std::swap(arr.at(i), arr.at(j));
        }
    }
    std::swap(arr.at(i + 1), arr.at(high));
    return i + 1;
}

void Sorting::quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int el = partition(arr, low, high);
        quickSort(arr, low, el - 1);
        quickSort(arr, el + 1, high);
    }
}

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    std::vector<int> temp = {};
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = left; k <= right; k++)
    {
        arr[k] = temp[k - left];
    }
}

void Sorting::mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}