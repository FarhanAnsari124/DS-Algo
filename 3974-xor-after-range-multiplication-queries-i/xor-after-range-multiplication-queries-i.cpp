class Solution {
public:
    long long MOD=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            int idx=queries[i][0];
            while(idx<=queries[i][1]){
                nums[idx]=(nums[idx]%MOD*queries[i][3]%MOD)%MOD;
                idx+=queries[i][2];
            }
        }
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans^=nums[i];
        }
        return ans;
    }
};