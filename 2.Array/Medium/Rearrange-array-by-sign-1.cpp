// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
// Without altering the relative order of positive and negative elements, you must return an array of alternately
// positive and negative values.
// Note: Start the array with positive elements.

// arr[] = {1,2,-4,-5}, N = 4  -> [1 -4 2 -5]  
// elements order are not changed, 1 comes before 2 and -4 comes before -5 


// NAIVE -> O(n) + O(n) [ 2 array -> O(n/2) + O(n/2) = O(n) SPACE ]
// one array to store positives and second to store negatives, lastly put the elements in original array

// for(int i=0;i<n/2;i++){
      
//       A[2*i] = pos[i];
//       A[2*i+1] = neg[i];
//   }


// OPTIMAL -> O(n) + O(n) [ 1 array ]


#include<bits/stdc++.h>
using namespace std;

    vector<int> RearrangebySign(vector<int>A){
        
    int n = A.size();
    
    // Define array for storing the ans separately.
    vector<int> ans(n,0);
    
    // positive elements start from 0 and negative from 1.
    int posIndex = 0, negIndex = 1;
    for(int i = 0;i<n;i++){
        
        // Fill negative elements in odd indices and inc by 2.
        if(A[i]<0){
            ans[negIndex] = A[i];
            negIndex+=2;
        }
        
        // Fill positive elements in even indices and inc by 2.
        else{
            ans[posIndex] = A[i];
            posIndex+=2;
        }
    }
    
    return ans;
    
}

