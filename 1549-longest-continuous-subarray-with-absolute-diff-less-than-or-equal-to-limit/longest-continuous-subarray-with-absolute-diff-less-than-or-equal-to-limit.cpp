class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>s;
        int i=0,j=0;
        int ans=0;
        int n=nums.size();
        while(i<n && j<n){
            s.insert(nums[j]);
            int maxi=*s.rbegin();
            int mini=*s.begin();
            while((maxi-mini)>limit){
                s.erase(s.find(nums[i]));
                maxi=*s.rbegin();
                mini=*s.begin();
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};