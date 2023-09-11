#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int>arr{10,20,0,21,0,0,21,20};
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[cnt]);
            cnt++;
        }
    }

    for(int &x:arr){
        cout<<x<<" ";
    }

    return 0;
}