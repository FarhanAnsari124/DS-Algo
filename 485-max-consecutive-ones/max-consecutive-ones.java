class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int curr_ones=0;
        int max_ones=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                curr_ones++;
                max_ones=Math.max(max_ones,curr_ones);
            }else{
                curr_ones=0;
            }
        }
        return max_ones;
    }
}