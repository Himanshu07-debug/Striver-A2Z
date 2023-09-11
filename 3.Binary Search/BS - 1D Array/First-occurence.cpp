// Given a sorted array of N integers, write a program to find the index of the first occurrence of the target key. 
// If the target is not found then return -1.

// array[] = {3,4,13,13,13,20,40}, target=13 -->  Output: 2
// array[] = {10,20,30}, target=15 -->  Output: -1

// NAIVE : O(n) -> Linear Search
// Optimal : O(logn) -> Binary Search

#include<bits/stdc++.h>

using namespace std;

int solve(int n, int key, vector < int > & v) {
  int start = 0;
  int end = n - 1;
  int res = -1;

  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (v[mid] == key) {
      res = mid;
      end= mid - 1;                             
    //   start = mid + 1;    in case of finding the last occurence
    } 
    else if (key < v[mid]) {
      end = mid - 1;
    } 
    else {
      start = mid + 1;
    }
  }
  return res;
}

int main() {
  int n = 7;
  int key = 13;
  vector < int > v = {3,4,13,13,13,20,40};
  
  cout << solve(n, key, v) << "\n";

  return 0;
}