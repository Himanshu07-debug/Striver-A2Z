// You are given an array of ‘N’ integers. 
// You need to find the length of the longest sequence which contains the consecutive elements.

// [100, 200, 1, 3, 2, 4]   --> 4 {1,2,3,4}

// NAIVE -> O(n^2)  [ Linear Search ]
// Better -> O(n*logn) [ SORTING ]
// Optimal -> O(n) + O(n) [ SET ]

#include <bits/stdc++.h>
using namespace std;

// NAIVE --->

bool linearSearch(vector<int>&arr, int num) {
    int n = arr.size(); 
    for (int i = 0; i < n; i++) {
        if (arr[i] == num)
            return true;
    }
    return false;
}

int Naive(vector<int>&arr){
    
    int n = arr.size();
    int max_cnt = INT_MIN;

    for(int i=0;i<n;i++){

        int x = arr[i];
        int cnt = 1;

        if(linearSearch(arr,x-1)==false){

            while(linearSearch(arr,x+cnt)==true){
                cnt+=1;
            }

        }

        max_cnt = max(max_cnt,cnt);
    }
    return max_cnt;
}


// OPTIMAL ---> 


#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int>&a) {

    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (int i=0;i<n;i++) {

        //if 'it' is a starting number:
        if (st.find(a[i] - 1) == st.end()) {
            
            //find consecutive numbers:
            int cnt = 1;
            while (st.find(a[i] + cnt) != st.end()) {
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }

    }
    return longest;

}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

