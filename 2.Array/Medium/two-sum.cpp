// Given an array of integers arr[] and an integer target.

// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

// 2nd variant: Return indices of the two numbers that sums to target. Otherwise, we will return {-1, -1}.



// NAIVE -> O(n^2) + O(1)

// Better -> O(n) + O(n) [ HashSet (for 1st variant) / HashMap (for 2nd Variant) ]

// DIS-ADVANTAGE OF Hashset/hashmap -> In worst Case, find() takes O(n) time

// If Interviewer do not allow you to use HashMap, then ->
// Optimal -> O(n*logn) + O(1) [ 2-pointer Approach ]


#include <bits/stdc++.h>
using namespace std;

// Better ------------------------------------>>>

vector<int> TwoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

// OPTIMAL ------------------------------------>>>

vector<int> twoSum(int n, vector<int> &arr, int target) {

    // sorting ->
    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return {left , right};
        }
        else if (sum < target) left++;
        else right--;
    }
    return {-1,-1};
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "Answer is [ " << ans[0] << ", "<< ans[1] << "]" << endl;
    return 0;
}



