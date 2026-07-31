class Solution {
public:
    map<tuple<int,int,int>,int>dp;
    int solve(int i, int j, int n, int m,vector<int>& nums, vector<int>& mult) {
        if (m==mult.size())return 0;
        auto key=make_tuple(i, j, m);
        if(dp.count(key))return dp[key];
        int left=nums[i]*mult[m]+solve(i+1,j,n,m+1,nums,mult);
        int right=nums[j]*mult[m]+solve(i,j-1,n,m+1,nums,mult);
        return dp[key]=max(left, right);
    }
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        int n=nums.size();
        return solve(0,n-1,n,0,nums,mult);
    }
};