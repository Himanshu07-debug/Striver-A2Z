// Hum Binary Search Monotonic search space pe hi laga sakte hai
// So no matter hum Rotated array ke 2 part me se koi bhi part pe ho, we will seach that which side is sorted so that 
// we can search our target there

// We basically compare arr[mid] with arr[low] && arr[high] in the following way:
// If arr[low] <= arr[mid]: In this case, we identified that the left half is sorted.
// If arr[mid] <= arr[high]: In this case, we identified that the right half is sorted.

// Rotated sorted array ensure krta hai ki uske dono part sorted hai fixed ranges pe

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                // element exists:
                high = mid - 1;
            }
            else {
                // element does not exist:
                low = mid + 1;
            }
        }
        else { 
            // if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                // element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}

