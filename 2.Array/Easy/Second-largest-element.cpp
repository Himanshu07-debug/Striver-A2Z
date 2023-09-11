#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr{10,9,10,8};
    int n=arr.size();
    int largest=0;
    int slargest=-1;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[largest]){
            slargest=largest;
            largest=i;
        }
        else if(arr[i]<arr[largest]){
            if(slargest==-1 || arr[slargest]<arr[i]){
                slargest=i;
            }
        }
    }
    if(slargest!=-1){
        cout<<"Second largest element is "<<arr[slargest];
    }
    else{
        cout<<"Second largest element not found";
    }
    return 0;
}