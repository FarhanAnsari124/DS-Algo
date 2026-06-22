class Solution {
    int lower_bound(int[] nums,int target){
        int n=nums.length;
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                ans=Math.min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    int upper_bound(int[] nums,int target){
        int n=nums.length;
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>target){
                ans=Math.min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    public int[] searchRange(int[] nums, int target) {
        int n=nums.length;
        if(n==0){
            return new int []{-1,-1};
        }
        int []res = new int[2];
        res[0]=lower_bound(nums,target);
        res[1]=upper_bound(nums,target)-1;
        if(res[0]==n || nums[res[0]]!=target){
            return new int []{-1,-1};
        }
        return res;
    }
}