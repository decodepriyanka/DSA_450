// Q - Given an array of size N.The task is to find the maximum and the minimum element of the array using the minimum number of comparisons

//  Approach 1 : using struct

#include <iostream>

using namespace std;

// Creating struct since we are not able to return multiple values in a function at a time
struct Pair
{
    int min;
    int max;
};

Pair getminmax(int arr[], int n)
{
    Pair minmax;
    int i;
    if (n == 1)
    {
        minmax.min = arr[0];
        minmax.max = arr[0];
    }
    if (arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }
    for (i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)
        {
            minmax.max = arr[i];
        }
        else if (arr[i] < minmax.min)
            minmax.min = arr[i];
    }
    return minmax;
}
int main()
{
    int arr[] = {1000, 11, 445,
                 1, 330, 3000};
    int arr_size = 6;
    struct Pair minmax = getminmax(arr, arr_size);

    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max;

    return 0;
}

// -- -- -- -- -- -- -- -- -Approach 2 - USING PAIR(C++ STL)-- -- -- -- -- -- --Note - Pair is a class in C++ stl

#include <bits/stdc++.h>

using namespace std;

pair<int, int> findMinMax(int arr[], int n)
{
    pair<int, int> t;

    if (arr[0] > arr[1])
    {
        t.first = arr[1];
        t.second = arr[0];
    }
    else
    {
        t.first = arr[0];
        t.second = arr[1];
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i] > t.second)
            t.second = arr[i];
        else if (arr[i] < t.first)
            t.first = arr[i];
    }
    return t;
}

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> res = findMinMax(arr, arr_size);

    cout << res.first << endl;
    cout << res.second;

    return 0;
}
