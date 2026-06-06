class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        while(j<n && nums[j]!=0)j++;
        int i=j+1;
        while(i<n){
            while(i<n && nums[i]==0)i++;
            if(i>=n)return;
            swap(nums[i],nums[j]);
            j++;
            i++;
        }
    }
};