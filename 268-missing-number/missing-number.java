class Solution {
    int linearSearch(int []nums,int target){
        for(int i=0;i<nums.length;i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
    public int missingNumber(int[] nums) {
        int n=nums.length;
        for(int i=0;i<=n;i++){
            if(linearSearch(nums,i)==-1){
                return i;
            }
        }
        return -1;
    }
}