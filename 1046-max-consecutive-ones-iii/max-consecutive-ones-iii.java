class Solution {
    public int longestOnes(int[] nums, int k) {
        int i=0;
        int j=0;
        int len=0;
        int maxlen=0;
        int zeroz=0;
        int n=nums.length;
        while(j<n){
            if(nums[j]==0){
                zeroz++;
            }
            while(zeroz>k){
                if(nums[i]==0)zeroz--;
                i++;
            }
            len=j-i+1;
            maxlen=Math.max(len,maxlen);
            j++;
        }
        return maxlen;
    }
}