class Solution {
public:
    bool solve(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>=j)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=solve(s,i+1,j-1,dp);
        }else{
            return dp[i][j]=false;
        }
    }
    string longestPalindrome(string s) {
        int maxl=-1;
        int st=-1;
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(maxl<1){
                maxl=1;
                st=i;
            }
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                if(maxl<2){
                    maxl=2;
                    st=i;
                }
            }
            
        }
        for(int l=3;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    if(maxl<l){
                        maxl=l;
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,maxl);
    }
};