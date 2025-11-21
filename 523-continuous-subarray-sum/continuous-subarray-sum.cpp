class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>psum(n+1,0);
        for(int i=1;i<=n;i++){
            psum[i]=nums[i-1]+psum[i-1];
        }
        unordered_map<long long,int>mapy;
        mapy[0]=0;
        for(int i=1;i<=n;i++){
            long long rem=(psum[i]%k+k)%k;
            if(mapy.find(rem)!=mapy.end()){
                if(i-mapy[rem]>1)
                return true;
            }
            else mapy[rem]=i;
        }
        return false;
    }
};