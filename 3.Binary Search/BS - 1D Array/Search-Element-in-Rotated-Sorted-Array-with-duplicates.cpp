// We can use the Rotated-sorted-array approach to think about this solution

// Our Rotated-sorted-array works fine for distinct elements -> 
// means we have to handle only the duplicates part, for the rest of the thing, that code will work

// More specifically, Rotated wala approach tab nhi chalega jab arr[low] = arr[mid] = arr[high].
// Jab teeno values same hai to hum correctly batana sorted half konsa hai is not possible, so there are possibility
// hai wrong half me enter krne ki
// To understand the problem -> [1,0,1,1,1], SEE this

// condition arr[mid] == k ko test karne ke baad we are assure that ki arr[mid]==k nhi hai
// so in this case, arr[low] = arr[mid] = arr[high] , hum dono taraf se boundary kam kar sakte hai, kyuki yeah answer 
// kabhi nhi honge, i.e TRIMIING THE SEARCH SPACE

// Agar aap aache se sochonge test case then your answer can be at any side of the current mid, Isliye answer lose na 
// hoye galat selection se, it is safe to reduce the search space when we are assured
// [1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1]   , k = 13  -> k at left side of the first calculated mid
// [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1]   , k = 2  -> k at right side of the first calculated mid
// Isliye mid ko kisi ek either low and high se compare krke hum decision nhi le sakte konse side chale

#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case: 
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {   // checking for both is V . V . IMP
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}
