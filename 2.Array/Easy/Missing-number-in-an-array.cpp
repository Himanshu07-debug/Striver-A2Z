// Given an integer n and an array of size n-1 containing n-1 numbers between 1 to n. Find the number(between 1 to n), 
// that is not present in the given array.

/*
Brute : Loop chaleange 1 to n array pe aur jo number present nhi honga, wo return -> O(n^2)
Better: Making a auxiliary array of size n to calculate frequency, jiski 0 rah gyi, wo ans   --> O(n) + O(n)

Optimal 1 : n*(n+1)/2 - (sum of array elements) => Missing Number
Optimal 2 : Using XOR

*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n=5;
    vector<int>arr{1,2,4,5};
    int size=arr.size();

    int x=0;
    for(int i=1;i<=n;i++){
        x = x^i;
    }

    for(int &y:arr){
        x=x^y;
    }

    cout<<"Missing Element is "<<x;

// XOR application -> find the Number occuring once and other occuring twice

    return 0;
}