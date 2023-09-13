// Given an array of integers, rotating array of elements by k elements either left or right.

// NAIVE -> O(n*k) [ for k times, do left/right rotate the array by 1 ]

// Better : O(n) + O(k) [extra array]

// Optimal : O(n) [Reversal algo]

// Reversal Algorithm ->

// Step 1: Reverse the last k elements of the array.
// Step 2: Reverse the first n-k elements of the array.
// Step 3: Reverse the whole array.

// Better ------------------------------------------------->>>

#include <bits/stdc++.h>
using namespace std;
void Rotatetoleft(int arr[], int n, int k)
{
    if (n == 0)
        return;

    // making input large k value to be within n
    k = k % n;

    int temp[k];

    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - n + k];
    }
}

// In order to rotate to right, array ke last ke k elements lelo temp me and then start shifting, and at last starting
// me temp ke values daal dena

// OPTIMAL ---------------------------------------------->>>

void Reverse(int arr[], int start, int end)
{
    while (start <= end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void Rotateletoright(int arr[], int n, int k)
{
    // Reverse first n-k elements
    Reverse(arr, 0, n - k - 1);
    // Reverse last k elements
    Reverse(arr, n - k, n - 1);
    // Reverse whole array
    Reverse(arr, 0, n - 1);
}



int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    Rotatetoleft(arr, n, k);
    cout << "After Rotating the elements to left " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
