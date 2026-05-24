class Solution {
public:
    int n;
    vector<int>dp;
    int solve(int i,vector<int>&arr,int d){
        if(dp[i]!=-1)return dp[i];
        int ans=1;
        for(int x=1;x<=d;x++){
            int ni=i-x;
            if(ni<0 || arr[ni]>=arr[i])break;
            ans=max(ans,1+solve(ni,arr,d));
        }
        for(int x=1;x<=d;x++){
            int ni=i+x;
            if(ni>=n || arr[ni]>=arr[i])break;
            ans=max(ans,1+solve(ni,arr,d));
        }
        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        dp.assign(n,-1);
       int maxi=1;
       for(int i=0;i<n;i++){
            maxi=max(maxi,solve(i,arr,d));
       }
       return maxi;
    }
};