class Solution {
public:
    int lcs(int m,int n,string &t1,string &t2,vector<vector<int>>&dp){
        if(m==0 || n==0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        if(t1[m-1]==t2[n-1]){
           return dp[m][n]=1+lcs(m-1,n-1,t1,t2,dp);
        }
        else{
            return dp[m][n]=max(lcs(m-1,n,t1,t2,dp),lcs(m,n-1,t1,t2,dp));
        }
    }
    int longestCommonSubsequence(string t1, string t2) {
        int i=t1.size();
        int j=t2.size();
        vector<vector<int>>dp(i+1,vector<int>(j+1,0));
        for(int m=1;m<=i;m++){
            for(int n=1;n<=j;n++){
                if(t1[m-1]==t2[n-1]){
                    dp[m][n]=1+dp[m-1][n-1];
                }
                else{
                    dp[m][n]=max(dp[m-1][n],dp[m][n-1]);
                }
            }
        }
        return dp[i][j];
      
    }
};