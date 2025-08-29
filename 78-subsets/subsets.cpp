class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int n,vector<int>empty,vector<int>&nums){
        if(i==n){
            ans.push_back(empty);
            return;
        }
        empty.push_back(nums[i]);
        solve(i+1,n,empty,nums);
        empty.pop_back();
        solve(i+1,n,empty,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>empty;
        solve(0,n,empty,nums);
        return ans;
        
    }
};