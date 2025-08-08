class Solution {
public:
    int solve(int i,int target,vector<int>& c,vector<vector<int>>&dp){
        if(target==0){
            return 0;
        }
        if(i==0){
            int cnt=0;
            while(c[0]<=target){
                target-=c[0];
                cnt++;
            }
            if(target==0)return cnt;
            return 1e9;
        }
        if(dp[i][target]!=-1)return dp[i][target];
        int nt=0+solve(i-1,target,c,dp);
        int t=1e9;
        if(target>=c[i])
        t=1+solve(i,target-c[i],c,dp);

        return dp[i][target]=min(nt,t);
    }
    int coinChange(vector<int>& c, int amount) {
        int n=c.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,c,dp);
        if(ans==1e9)return -1;
        return ans;
    }
};