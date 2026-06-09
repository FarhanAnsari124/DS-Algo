class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = LLONG_MAX;
        long long maxi = LLONG_MIN;
        for(long long x:nums){
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        long long ans=k*(maxi-mini);
        return ans;
    }
};