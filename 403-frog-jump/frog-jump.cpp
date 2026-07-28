class Solution {
public:
    bool solve(int i,int last,int n,map<int,int>&st,vector<int>&stone,vector<vector<int>>&dp){
        if(i==n-1){
            return dp[i][last]= true;
        }
        if(i>=n){
            return false;
        }
        if(last > n)return false;
        if(dp[i][last]!=-1){
            return dp[i][last];
        }
        bool jump=false;
        for(int d=-1;d<=1;d++){
            int nj = last+d;
            if(nj<=0)continue;
            int nstone = stone[i]+nj;
            if(st.contains(nstone)){
                jump= jump ||  solve(st[nstone],nj,n,st,stone,dp);
            }
           
        }
        return dp[i][last]=jump;
    }
    bool canCross(vector<int>& stone) {
        map<int,int>st;
        int n=stone.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            st[stone[i]]=i;
        }
        return solve(0,0,stone.size(),st,stone,dp);
    }
};