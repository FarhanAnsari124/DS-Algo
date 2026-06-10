class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int cal_sum=n*(n+1)/2;
        int ac_sum=0;
        for(auto x:nums){
            ac_sum+=x;
        }
        return cal_sum-ac_sum;
    }
};