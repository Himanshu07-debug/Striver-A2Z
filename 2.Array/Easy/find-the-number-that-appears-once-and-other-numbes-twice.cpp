// Find the number that appears once, and the other numbers twice

// Brute -> O(n^2)

// Naive -> O(n) + O(n) [Finding max and making an array of max size for frequency calculation]

// Better -> O(n) + O(n) [ HASHMAP ]

// Optimal -> O(n) + O(1) [ XOR ]




#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr) {
    //size of the array:
    int n = arr.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}
