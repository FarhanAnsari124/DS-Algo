class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last=-1e9;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1 && last!=-1e9){
                if(i-last-1<k)return false;
            }
            if(nums[i]==1){
                last=i;
            }
        }
        return true;
    }
};