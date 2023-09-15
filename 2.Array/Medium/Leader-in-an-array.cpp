// Given an array, print all the elements which are leaders.
// A Leader is an element that is greater than all of the elements on its right side in the array.

// arr = [4, 7, 1, 0]   ->   7 1 0

// NAIVE -> O(n^2) [ 2 loops ]  + O(n)

// Optimal -> O(n) + O(n)


#include<bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int arr[], int n) {

    vector<int> ans;
    
    // Last element of an array is always a leader,
    // push into ans array.
    int max = arr[n - 1];
    ans.push_back(arr[n-1]);

    // Start checking from the end whether a number is greater
    // than max no. from right, hence leader.
    for (int i = n - 2; i >= 0; i--){
        if (arr[i] > max) {
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }
    
    return ans;
}

int main() {
    
  // Array Initialization.
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};

    vector<int> ans = printLeaders(arr,n);
    
    // REVERSE LOOP
    for(int i = ans.size()-1;i>=0;i--){
        
        cout<<ans[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}
