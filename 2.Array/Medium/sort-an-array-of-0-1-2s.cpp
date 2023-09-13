// Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using 
// inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]


// Naive -> O(n*logn) + O(n) [ Sorting ]

// Better -> O(n) + O(1)  [ 2 loops ]
// [using 3 variables to count 0,1,2 and then filling the original array ]

// Optimal -> O(n) + O(1) [ single loop ]  ( DNF sort )

// Explanation : "https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/"

// Little-bit HINT ->
// arr[0….low-1] contains 0. [Extreme left part]
// arr[low….mid-1] contains 1.
// arr[high+1….n-1] contains 2. [Extreme right part]
// The middle part i.e. arr[mid….high] is the unsorted segment.


#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}




