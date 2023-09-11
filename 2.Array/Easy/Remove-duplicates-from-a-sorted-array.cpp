#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {
        int cnt=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=arr[i-1]){
                arr[cnt]=arr[i];
                cnt++;
            }
        }
        return cnt;
}

int main(){
    vector<int>arr{10,10,20,20,20,30,30,30,30,40};
    int n=arr.size();

    int cnt = removeDuplicates(arr);

    for(int i=0;i<cnt;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}