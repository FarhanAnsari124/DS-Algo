class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int cal_xor=0;
        int ac_xor=0;
        for(int i=0;i<n;i++){
            cal_xor^=i;
            ac_xor^=nums[i];
        }
        cal_xor^=n;
        return cal_xor^ac_xor;
    }
};