class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>ssum(n,0);
        ssum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ssum[i]=ssum[i+1]+nums[i];
        }
        int psum=0;
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            res[i]=abs(psum-(ssum[i]-nums[i]));
            psum+=nums[i];
        }
        return res;
    }
};