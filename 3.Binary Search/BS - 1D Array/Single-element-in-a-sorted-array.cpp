// Given an array of N integers. Every number in the array except one appears twice. Find the single number in the 
// array.
// {1,1,2,2,3,3,4,5,5,6,6} -> 4   |||||||   {1,1,3,5,5}  -> 3

// BRUTE -> O(n) -> Ek loop chalake element search krna hai (Peak element me jaise humne ek hi if me kiye the)
// Better -> O(n) -> Using XOR
// Best -> O(logn) -> Binary Search

// Apna logic -> 
// Agar Current mid element Single element nhi hua , then ->
// Agar mid aur mid+1 wale same hai, to left side me agar number of elements even nhi hue tabhi jayenge i.e (mid&1)
// Yaa to mid, mid-1 equal hue to mid-1 ke aage wale number of elements even nhi hue tabhi jaynge


// Striver Bhaiya Logic ->
// In our array, elements will be present like this ->

// 1(even,odd) 2(even,odd) 3(single element) 4(odd,even) 5(odd,even)

// This means that ki Left side me mid even aaya to mid+1 same honga aur agar odd aaya to, mid-1 same honga
// Right side me issi ka ulta honga becz single element disturbs the arrangement of pairs 

// More simply ->
// If (i % 2 == 0 and arr[i] == arr[i+1]) or (i%2 == 1 and arr[i] == arr[i-1]), we are in the left half.
// If (i % 2 == 0 and arr[i] == arr[i-1]) or (i%2 == 1 and arr[i] == arr[i+1]), we are in the right half.



#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.

    //Edge cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}
