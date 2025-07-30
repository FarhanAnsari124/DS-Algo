class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int maxi=*max_element(nums.begin(),nums.end());
       int start=1e9;
       int end=-1e9;
       int maxlen=-1e9;
       for(int i=0;i<nums.size();i++){
        if(nums[i]==maxi){
            start=min(start,i);
            end=max(end,i);
            maxlen=max(maxlen,end-start+1);
            }
        else{
            start=1e9;
            end=-1e9;
           
        }
       }
       return maxlen;
    }
};