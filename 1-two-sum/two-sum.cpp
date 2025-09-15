class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mapy;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(mapy.find(rem)!=mapy.end()){
                return {i,mapy[rem]};
            }else{
                mapy[nums[i]]=i;
            }
        }
        return{};
    }
};