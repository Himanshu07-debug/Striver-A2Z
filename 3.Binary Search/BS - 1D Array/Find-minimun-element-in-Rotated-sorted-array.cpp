// Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated
//  between 1 to N times which is unknown. Find the minimum element in the array. 

// We can utilize our past knowledge of Rotated sorted array
// left side aaya mid to arr[low] possible ans hai ,rotation ke wajah se right side me bhi isase jyada min. possible
// right side aaya mid to arr[mid] possible ans hai , -> left side me isase jyada min. ho sakta hai

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}

// FURTHER OPTIMIZATION =>

// Agar kisi bhi moment pe hume completely sorted search space milta hai i.e arr[low] <= arr[high], then no need 
// to do further binary search kyuki yeah search space ka min. always arr[low] hai

// After calculating mid , write ->

        // if (arr[low] <= arr[high]) {
        //     ans = min(ans, arr[low]);
        //     break;
        // }
