class Solution {
public:
    int fnc(vector<int>&v,int n,int target,vector<vector<int>>&dp){
        if(target==0){
            return 0;
        }
        if(n==0){
            return 1e9;
        }
        if(dp[n][target]!=-1)return dp[n][target];
        int not_take=0+fnc(v,n-1,target,dp);
        int take=1e9;
        if(v[n-1]<=target){
            take=1+fnc(v,n,target-v[n-1],dp);
        }
        return dp[n][target]=min(not_take,take);
    }
    int numSquares(int n) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            double s=sqrt(i);
            if(floor(s)==ceil(s)){
                v.push_back(s*s);
            }
        }
        vector<vector<int>>dp(v.size()+1,vector<int>(n+1,-1));
        return fnc(v,v.size(),n,dp);
        // for(auto x:v){
        //     cout<<x<<" ";
        // }

        // return 0;
    }
};