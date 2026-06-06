class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1;
        int k=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]!=nums[k]){
                nums[k+1]=nums[j];
                k++;
            }
            j++;
        }
        return k+1;
    }
};