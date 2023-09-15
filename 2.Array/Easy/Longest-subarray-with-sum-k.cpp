// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

// Input Format: N = 3, k = 5, array[] = {2,3,5}
// Result: 2
// Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

// Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
// Result: 3
// Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.


// Brute : O(n^3) -> Getting all subarrays and calculating max length
// Naive : O(n^2) -> Subarray ke sum se lena dena hai, O(n^2) se bhi ho jayega
// Better : O(n) -> Hashing ( Becomes OPTIMAL when array contains negative and positive integers both )
// Optimal : O(n) -> Sliding window [ applicable only if array contains positive integers]




#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers

    // start the sum from the first elements
    long long sum = a[0];
    int maxLen = 0;

    while (right < n) {

        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

// TIME -> O(2 * n) [more precision], outer while loop will run at max for n times, same for inner while loop
