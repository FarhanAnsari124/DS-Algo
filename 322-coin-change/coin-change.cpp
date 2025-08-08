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
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int ans=solve(n-1,amount,c,dp);
        // if(ans==1e9)return -1;
        // return ans;

        for(int i=0;i<=amount;i++){
            if(i%c[0]==0){
                dp[0][i]=i/c[0];
            }else dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                int nt=0+dp[i-1][target];
                int t=1e9;
                if(target>=c[i])
                t=1+dp[i][target-c[i]];
                dp[i][target]=min(nt,t);
            }
        }
        if(dp[n-1][amount]==1e9)return -1;
        return dp[n-1][amount];
    }
};