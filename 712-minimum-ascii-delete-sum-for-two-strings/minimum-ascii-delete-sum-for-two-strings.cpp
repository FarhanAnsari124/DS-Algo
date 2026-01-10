class Solution {
public:
    // int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp,int m ,int n){
    //     if(i==m && j==n){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(i==m){
    //         return (int)s2[j]+solve(i,j+1,s1,s2,dp,m,n);
    //     }else if(j==n) return (int)s1[i]+solve(i+1,j,s1,s2,dp,m,n);
    //     else if(s1[i]==s2[j])return solve(i+1,j+1,s1,s2,dp,m,n);
    //     else return min((int)s1[i]+solve(i+1,j,s1,s2,dp,m,n),(int)s2[j]+solve(i,j+1,s1,s2,dp,m,n));
    // }
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
         for(int j=n-1;j>=0;j--) {
            dp[m][j]=dp[m][j+1]+(int)s2[j];
        }
        for(int i=m-1;i>=0;i--) {
            dp[i][n]=dp[i+1][n]+(int)s1[i];
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s1[i]==s2[j])dp[i][j]=dp[i+1][j+1];
                else dp[i][j]= min((int)s1[i]+dp[i+1][j],(int)s2[j]+dp[i][j+1]); 
            }
        }
        return dp[0][0];
    }
};