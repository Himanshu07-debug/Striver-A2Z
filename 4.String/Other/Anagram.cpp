// Check whether two strings are ANAGRAM or not ->

// ANAGRAM -> Two Strings having same number of characters, order can be different

// s1 = "listen" , s2 = "silent"  -> TRUE 

// NAIVE -> O(n*logn) [ Sorting & Compare ]

#include <bits/stdc++.h>
using namespace std;

bool Naive(const string &s1,const string &s2){
    
    if(s1.size()!=s2.size()){
        return false;
    }

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    for(int i=0;i<s2.size();i++){

        if(s1[i]!=s2[i]){
            return false;
        }

    }

    return true;

}

// BETTER -> O(n) + O(1) SPACE [ Use cnt[256]={0} array ]

// OPTIMAL -> O(n)  [ XOR ]