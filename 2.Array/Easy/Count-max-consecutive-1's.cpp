// Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.


#include <bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums) {
      int cnt = 0;
      int maxi = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
          cnt++;
        } 
        else {
          cnt = 0;
        }

        maxi = max(maxi, cnt);
      }
      return maxi;
}

int main(){
    vector<int>arr{ 1, 1, 0, 1, 1, 1};
    int n=arr.size();
    cout << "The maximum  consecutive 1's are " << findMaxConsecutiveOnes(arr);
    return 0;
}