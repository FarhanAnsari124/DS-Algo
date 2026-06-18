class Solution {
    public int missingNumber(int[] nums) {
        int n=nums.length;
        int sum_of_n=(n*(n+1))/2;
        int cal_sum=0;
        for(int i=0;i<n;i++){
            cal_sum+=nums[i];
        }
        return sum_of_n-cal_sum;
    }
}