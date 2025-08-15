class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[prev]<arr[i]){
                    dp[i]=max(1+dp[prev],dp[i]);
                }
            }
        }
        int ans=1;
        for(auto x:dp){
            ans=max(ans,x);
        }
        return ans;
    }
};