class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k=0;
        int n=nums.size();
        set<vector<int>>st;
        while(k<n-1){
            while(k>0 && k<n-1 && nums[k]==nums[k-1]){
                k++;
            }
            int target=-nums[k];
            int i=k+1;
            int j=n-1;
            while(i<j){
                if(nums[i]+nums[j]==target){
                    st.insert({-target,nums[i],nums[j]});
                    i++;
                    j--;
                    while(i<j && nums[i]==nums[i-1]){
                        i++;
                    }
                    while(i<j && nums[j]==nums[j+1]){
                        j--;
                    }
                }
                else if(nums[i]+nums[j]>target){
                    j--;
                }else{
                    i++;
                }
            }
            k++;
        }
        vector<vector<int>>v(st.begin(),st.end());
        return v;
    }
};