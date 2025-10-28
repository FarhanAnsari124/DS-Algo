class Solution {
public:
    set<vector<int>> st;
    void twoSum(vector<int>& a,int i,int j, int target) {
        int n=a.size();
        while(i<j){
            if(a[i]+a[j]==target){
                while(j-i>2 && a[j]==a[j-1])j--;
                while(j-i>2 && a[i]==a[i+1])i++;
                st.insert({-target,a[i],a[j]});
                i++;
                j--;
            }
            else if(a[i]+a[j]>target){
                j--;
            }else{
                i++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int target=0-nums[i];
            twoSum(nums,i+1,n-1,target);
        }
        vector<vector<int>> v(st.begin(),st.end());
        return v;

    }
};