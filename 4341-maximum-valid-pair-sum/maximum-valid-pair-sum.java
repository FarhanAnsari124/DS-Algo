class Solution {
    public int maxValidPairSum(int[] nums, int k) {
        int maxi=-1;
        int sum=0;
        int n=nums.length;
        for(int i=k;i<n;i++){
            maxi=Math.max(maxi,nums[i-k]);
            sum=Math.max(sum,nums[i]+maxi);
        }
        return sum;
    }
}