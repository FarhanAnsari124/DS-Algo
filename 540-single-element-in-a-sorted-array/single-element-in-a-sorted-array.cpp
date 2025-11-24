class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n=nums.size();
        int low=0;
        int high=n-1;
        if(n<3){
            if(n==1)return nums[0];
        }
        while(low<=high){
            int mid=(low+high)/2;
            if((mid==n-1 && nums[mid]!=nums[mid-1]) || (mid==0 && nums[mid]!=nums[mid+1])){
                return nums[mid];
            }
            else if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            else if(nums[mid]==nums[mid-1]){
                if((mid-low)%2==0){
                    high=mid-2;
                }else low=mid+1;
            }
            else if(nums[mid]==nums[mid+1]){
                if((high-mid)%2==0){
                    low=mid+2;
                }else high=mid-1;
            }
        }
        return -1;
    }
};