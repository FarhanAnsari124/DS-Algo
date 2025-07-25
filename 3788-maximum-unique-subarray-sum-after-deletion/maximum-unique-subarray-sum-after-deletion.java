class Solution {
    public int maxSum(int[] nums) {
       Arrays.sort(nums);
        int n = nums.length;
        if (nums[n-1]<=0){
            return nums[n-1];
        }
        HashSet<Integer> set = new HashSet<>();
        int ans = 0;
        for(int i = n-1; i>=0; i--){
            if (nums[i]<=0){
                break;
            }
            if (!set.contains(nums[i])){
                ans+=nums[i];
                set.add(nums[i]);
            }
        }
        return ans; 
    }
}