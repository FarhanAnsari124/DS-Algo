class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int prod=1;
        int cnt=0;
        
        while(j<n){
            prod*=nums[j];
            while(i<=j && prod>=k){
                prod/=nums[i];
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};