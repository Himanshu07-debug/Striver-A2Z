// Naive : O(n^3)
// Better : O(n^2)
// Optimal : O(n) [ Kadanes algo ]


// Eg -> [-5,1,-2,3..]
// let sum = -5, res = -5
// At each index, we have 2 choices, either to take it to the current sum or start a new sum with that index

// Subarray ending with index 1, [-5,1] -> -4 && [1] -> 1 , max(-4,1) -> 1, therefore we will start a new subarray 
// Subarray ending with index 2, [-5,1,-2], [1,-2], [-2] , max is [1,-2] , therefore we will continue the last subarray

#include<bits./stdc++.h>
using namespace std;

int main(){

    vector<int>arr = {-2,1,-3,4,-1,2,1,-5,4};
    int n=arr.size();

    int maxEnding = arr[0];
    int res=arr[0];
    int st=0, resStart=0, resEnd=0;

    for(int i=1;i<n;i++){

        // Starting with a new subarray
        if(maxEnding + arr[i] <= arr[i]){
            maxEnding = arr[i];
            st=i;
        }
        // continuing with the previous subarray
        else{
            maxEnding+=arr[i];
        }

        // Current Subarray sum is greater than resultant sum
        if(res<maxEnding){
            res=maxEnding;
            resStart = st;
            resEnd = i;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (res < 0) res = 0;


    cout<<"Maximum subarray sum is "<<res<<"\n";
    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = resStart; i <= resEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";

    return 0;
}


// One more way to do KADANE ->

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
        // Valid for all possible cases -> [-6,-1] -> -1 , [1,-6,2] -> 2
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
