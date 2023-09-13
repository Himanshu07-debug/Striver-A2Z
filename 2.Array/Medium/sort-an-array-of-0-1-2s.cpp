// Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using 
// inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]


// Naive -> O(n*logn) + O(n) [ Sorting ]

// Better -> O(n) + O(1)  [ 2 loops ]
// [using 3 variables to count 0,1,2 and then filling the original array ]

// Optimal -> O(n) + O(1) [ single loop ]  ( DNF sort )

// Explanation : "https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/"

