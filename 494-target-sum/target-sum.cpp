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
     int countPartitions(vector<int>& arr, int d) {
        int totsum=accumulate(arr.begin(),arr.end(),0);
        int s2=(totsum-d)/2;
        if((totsum-d)%2==1 || totsum-d<0 )return 0;
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(s2+1,0));
        // return solve(n-1,s2,arr,dp);
        if(arr[0]==0)dp[0][0]=2;
        else{
            dp[0][0]=1;
        }
        if(arr[0]!=0 && arr[0]<=s2)dp[0][arr[0]]=1;
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=s2;sum++){
                int nt=dp[ind-1][sum];
                int t=0;
                if(sum>=arr[ind]){
                    t=dp[ind-1][sum-arr[ind]];
                }
                dp[ind][sum]=nt+t;
            }
        }
        return dp[n-1][s2];
     }
    int findTargetSumWays(vector<int>& a, int target) {
        int n=a.size();
        // return solve(n-1,target,a);
        return countPartitions(a,target);
    }
};