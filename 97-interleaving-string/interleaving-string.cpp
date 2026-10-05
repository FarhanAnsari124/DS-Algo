class Solution {
public:
    bool solve(int i,int j,int k,string &s1, string &s2, string &s3,vector<vector<int>>&dp){
        if(i==s1.size() && j==s2.size())return true;
        if(dp[i][j]!=-1)return dp[i][j];
        bool ans=false;
        if(i<s1.size() && s1[i]==s3[k]){
            ans|=solve(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(j<s2.size() && s2[j]==s3[k]){
            ans|=solve(i,j+1,k+1,s1,s2,s3,dp);
        }
        return dp[i][j]=ans;
    }
    bool isInterleave(string s1,string s2,string s3){
    int n=s1.size();
    int m=s2.size();
    int p=s3.size();

    if(n+m!=p)return false;

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    dp[0][0]=true;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 && j==0)continue;

            int k=i+j-1;
            bool ans=false;

            if(i>0 && s1[i-1]==s3[k]){
                ans|=dp[i-1][j];
            }

            if(j>0 && s2[j-1]==s3[k]){
                ans|=dp[i][j-1];
            }

            dp[i][j]=ans;
        }
    }

    return dp[n][m];
}
};