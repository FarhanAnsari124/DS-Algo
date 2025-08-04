class Solution {
public:
    bool solve(int ind,int target,vector<int>& a,vector<vector<int>>&dp){
        if(target==0)return true;
        if(ind==0)return a[ind]==target;
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool nt=solve(ind-1,target,a,dp);
        bool t=false;
        if(target>=a[ind]){
            t=solve(ind-1,target-a[ind],a,dp);
        }
        return dp[ind][target]= t||nt;
    }
    bool canPartition(vector<int>& a) {
        int sum=accumulate(a.begin(),a.end(),0);
        int n=a.size();
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        if(sum%2!=0)return false;
        else{
            return solve(n-1,target,a,dp);
        }
        
    }
};