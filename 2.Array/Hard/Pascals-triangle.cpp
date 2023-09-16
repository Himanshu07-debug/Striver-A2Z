// Problem Statement: This problem has 3 variations. They are stated below:

// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

// N = 5, r = 5, c = 3
// 6 (for variation 1)
// 1 4 6 4 1 (for variation 2)

// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1    (for variation 3)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    vector<vector<int>>res= {{1},{1,1}};

    for(int i=2;i<n;i++){
        vector<int> v;
        for(int j=0;j<=i;j++){
            if(j==0 || j==i){
                v.push_back(1);
            }
            else{
                int cal = res[i-1][j-1] + res[i-1][j];
                v.push_back(cal);
            }
        }
        res.push_back(v);
    }

    for(auto v:res){
        for(int x:v){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    cout<<"Ans: "<<res[4][2];

    return 0;

}