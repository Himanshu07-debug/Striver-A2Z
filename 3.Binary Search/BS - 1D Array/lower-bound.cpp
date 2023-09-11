// Lowerbound of x in an array is a number equal to x(if present) or the next number greater than it

// arr[] = {1,2,2,3}, x = 2    -> O/P : 2
// arr[] = {3,5,8,15,19}, x = 9  -> O/P : 15

// NAIVE -> Linear Search
// OPTIMAL -> Binary Search

// In our CODE, we have to return the index of the lowerbound of x

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}

// UPPERBOUND -> A number next greater than x in an array, not equal to
// Inorder to find UpperBound, arr[mid] >= x will change to arr[mid] > x
