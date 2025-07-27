class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size();
        int start=n/3;
        sort(nums.begin(),nums.end());
        long long cnt=0;
        for(int i=start;i<n;i+=2){
            cnt+=nums[i];
        }
        return cnt;
    }
};