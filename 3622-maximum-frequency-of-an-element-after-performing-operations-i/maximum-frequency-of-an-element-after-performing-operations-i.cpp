class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mapy;
        for(auto x:nums)mapy[x]++;
        int ans=1;
        for(int i=nums[0];i<=nums[n-1];i++){
            auto it=lower_bound(nums.begin(),nums.end(),i-k);
            int st=distance(nums.begin(), it);
            it=upper_bound(nums.begin(),nums.end(),i+k);
            int en=distance(nums.begin(), it);
            int tot_count=en-st;
            int no_of_i=mapy[i];
            int req=tot_count-no_of_i;
            int freq=no_of_i+min(req,numOperations);
            ans=max(freq,ans);
        }
        return ans;
    }
};