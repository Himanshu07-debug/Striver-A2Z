// Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated 
// between 1 to N times which is unknown. Find how many times the array has been rotated.

// [4,5,6,7,0,1,2,3]   -> 4
// [3,4,5,1,2]   -> 3

// PAST KNOWLEDGE -> Hum inputs ko dekhe yaa dimag lagaye to we will find that number of rotation will be equal to 
//                      the index of the minimum element in rotated array, becz wo jitna aage rhnga starting se 
//                      utne  hi times array rotate hua honga
// We had solved a Problem -> minimum element in a rotated sorted array, use that LOGIC


#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {

    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {

        int mid = (low + high) / 2;

        // OPTMIZATION --------------------> 
        // If at any moment, agar humko completely sorted mil gya search space, Now directly while loop will break, we
        // will not get any element minimum than arr[low], check it and break, no need to do further computation
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                // Storing indexes
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else { 
            //if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}
