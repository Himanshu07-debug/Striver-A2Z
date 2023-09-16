#include<bits/stdc++.h>
using namespace std;

void call(vector<int>& nums, int st,int en, int sum,set<vector<int>> &s){
    unordered_set<int>sta;
    for(int i=st;i<=en;i++){
        if(sta.find(sum-nums[i])!=sta.end()){
            int first = min(-sum,min(nums[i],sum-nums[i]));
            int last = max(-sum,max(nums[i],sum-nums[i]));
            int middle = -(first+last);
            s.insert({first,middle,last});
        }
        sta.insert(nums[i]);
    }
}

    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0;i<n;i++){
            call(nums,i+1,n-1,-nums[i],s);
        }

        for(auto x:s){
            res.push_back(x);
        }
        return res;
    }