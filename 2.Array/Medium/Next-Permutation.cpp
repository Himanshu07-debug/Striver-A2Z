//  Rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
// If such an arrangement is not possible, it must rearrange to the lowest possible order 
// (i.e., sorted in ascending order).


// NAIVE -> Generate all Permutations + Linear search for the I/P permutation + return the next Permutation
//          Time : O (N! * N )

// BETTER -> using STL built-in function  -> O(N)

//  OPTIMAL ->