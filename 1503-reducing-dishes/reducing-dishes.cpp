class Solution {
public:
    int solve(int i,int k,vector<int>&v,vector<vector<int>>&dp){
        if(i==v.size()){
            return 0;
        }
        if(dp[i][k]!=-1)return dp[i][k];
        int nt = solve(i+1,k,v,dp);
        int take = (v[i]*k) + solve(i+1,k+1,v,dp);
        return dp[i][k] =  max(nt,take);
    }
    int maxSatisfaction1(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        for(int i=n-1;i>=0;i--){
            for(int k=n;k>=1;k--){
                int nt = dp[i+1][k];
                int take = (v[i]*k) + dp[i+1][k+1];
                dp[i][k] =  max(nt,take);
            }
        }
        for(auto x:dp){
            for(int y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        return dp[0][1];
    }
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        int csum=0;
        int tsum=0;
        int n=v.size();
        for(int i=n-1;i>=0;i--){
            csum+=v[i];
            if(csum<0)return tsum;
            tsum+=csum;
        }
        return tsum;
    }
};