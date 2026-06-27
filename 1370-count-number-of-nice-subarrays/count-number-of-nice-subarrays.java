class Solution {
    int func(int []nums,int goal){
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        int n=nums.length;
        if(goal<0){
            return 0;
        }
        while(r<n){
            sum+=(nums[r]%2);
            while(l<=r && sum>goal){
                sum-=(nums[l]%2);
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    public int numberOfSubarrays(int[] nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
}