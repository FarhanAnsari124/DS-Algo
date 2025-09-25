class Solution {
public:
    set<vector<int>>ans;
    void solve(int i,int n,vector<int>& nums,vector<int>&temp,int back){
        if(i==n){
            if(temp.size()<2)return;
            ans.insert(temp);
            return;
        }
        if(nums[i]>=back){
            temp.push_back(nums[i]);
            solve(i+1,n,nums,temp,nums[i]);
            temp.pop_back();
        }
        solve(i+1,n,nums,temp,back);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        solve(0,n,nums,temp,-101);
        vector<vector<int>>a;
        for(auto x:ans){
            a.push_back(x);
        }
        return a;
    }
};