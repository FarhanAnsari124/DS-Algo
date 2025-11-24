class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int,int>mapy;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mapy[nums[i]]=i;
        }
        if(mapy.find(target)!=mapy.end())
        return mapy[target];
        else return -1;
    }
};