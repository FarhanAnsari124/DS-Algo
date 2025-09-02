class Solution {
public:
    int b_s(vector<int>&nums,int target,int l,int n){
        int low=l;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            int sec=b_s(nums,rem,i+1,n);
            if(sec==-1)continue;
            else{
                return {i+1,sec+1};
            }
        }
        return {};

        
    }
};