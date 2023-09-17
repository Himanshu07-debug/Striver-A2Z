// Find one extra character in a string

// I/P -> S1 = abcd , S2 = abecd               O/P => e
// NOTE : S2.size() > S1.size()  always


// NAIVE ---------------------------------------> 

// [ Sort Both array and then compare ]
// TIME -> O(n*logn) 


#include <bits/stdc++.h>
using namespace std;

char Naive(string s1,string s2){
    
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    for(int i=0;i<s2.size();i++){

        if(s1[i]!=s2[i]){
            return s1[i];
        }

    }

    return s1[s2.size()];

}

// BETTER -> Using Auxiliary array to act as frequency calculator

char Better(string s1,string s2){

    int cnt[256]={0};

    for(char x:s1){
        cnt[x]++;
    }

    for(char x:s2){
        cnt[x]--;
    }

    for(int i=0;i<256;i++){                     // Traversal of constant no. -> O(1) TIME
        if(cnt[i]==1){
            return (char)i;
        }
    }
}

// TIME -> O(n)    , SPACE ->  O(256) i.e O(1)


// OPTIMAL APPROACH ------------------------------------------> 

// XOR [ O(n) + O(1) Space ]

char Optimal(string s1,string s2){

    int xorr = 0;

    for(int i=0;i<s2.size();i++){
        xorr = xorr ^ s1[i] ^ s2[i];
    }

    xorr ^= s1[s2.size()];

    return (char)xorr;

}

int main()
{
    string s1 = "abcd";
    string s2 = "cbdad";
    cout << Optimal(s1, s2) << endl;
    return 0;
}