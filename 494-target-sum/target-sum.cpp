class Solution {
public:
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
        int plus=solve(i-1,t-a[i],a);
        int minus=solve(i-1,t+a[i],a);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& a, int target) {
        int n=a.size();
        return solve(n-1,target,a);
    }
};