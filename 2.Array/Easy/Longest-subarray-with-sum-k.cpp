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
int main(){
    
    return 0;
}