class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int cal_xor=0;
        for(int i=0;i<=n;i++)cal_xor^=i;
        int ac_xor=0;
        for(auto x:nums){
            ac_xor^=x;
        }
        return cal_xor^ac_xor;
    }
};