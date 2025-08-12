class Solution {//S1=p S2=s
public:
    bool solve(int i,int j,string &p,string &s,vector<vector<int>>&dp){
        if(i==0 && j==0)return true;
        if(i==0 && j>0)return false;
        if(j==0 && i>0){
            for(int k=0;k<i;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(p[i-1]==s[j-1] || p[i-1]=='?'){
            return dp[i][j]=solve(i-1,j-1,p,s,dp);
        }
        if(p[i-1]=='*'){
            return dp[i][j]= (solve(i-1,j,p,s,dp)||solve(i,j-1,p,s,dp));
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,p,s,dp);
        
    }
};