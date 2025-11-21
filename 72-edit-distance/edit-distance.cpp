class Solution {
public:
    int ed(int m,int n,string &w1,string &w2,vector<vector<int>>&dp){
        if(!m)
            return n;
        else if(!n)
            return m;
        if(dp[m][n]!=-1)return dp[m][n];
        if(w1[m-1]==w2[n-1])
            return dp[m][n]=ed(m-1,n-1,w1,w2,dp);
        else 
            return dp[m][n]=1+min({ed(m-1,n-1,w1,w2,dp),ed(m-1,n,w1,w2,dp),ed(m,n-1,w1,w2,dp)});
    }
    int minDistance(string w1, string w2) {
        int m=w1.size();
        int n=w2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return ed(m,n,w1,w2,dp);
    }
};