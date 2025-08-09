class Solution {
public:
    unordered_map<int,unordered_map<int,int>>dp;
    int solve(int i,int t,vector<int>& a){
        if(i==0){
            if(a[i]==0 && a[i]==abs(t)){
                return 2;
            }
            if(a[i]==abs(t)){
                return 1;
            }

            else return 0;
        }
        if(dp[i][t]!=0)return dp[i][t];
        int plus=solve(i-1,t-a[i],a);
        int minus=solve(i-1,t+a[i],a);
        return dp[i][t]= plus+minus;
    }
    int findTargetSumWays(vector<int>& a, int target) {
        int n=a.size();
        return solve(n-1,target,a);
    }
};