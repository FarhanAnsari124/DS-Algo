class Solution {
public:
    vector<int>maxs;
    void solve(int i,int n,vector<int>&empty,vector<int>&nums){
        if(i>=n){
            int Or=0;
            for(auto x:empty){
                Or=Or|x;
            }
            maxs.push_back(Or);
            return;
        }
        empty.push_back(nums[i]);
        solve(i+1,n,empty,nums);
        empty.pop_back();
        solve(i+1,n,empty,nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>empty;
        solve(0,n,empty,nums);
        int maxi=*max_element(maxs.begin(),maxs.end());
        int cnt=0;
        for(auto x:maxs)if(x==maxi)cnt++;
        return cnt;
    }
};