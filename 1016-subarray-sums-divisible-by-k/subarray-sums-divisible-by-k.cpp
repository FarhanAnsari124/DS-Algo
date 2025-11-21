class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>psum(n+1,0);
        for(int i=1;i<=n;i++){
            psum[i]=nums[i-1]+psum[i-1];
        }
        unordered_map<long long,int>mapy;
        mapy[0]=1;
        long long cnt=0;
        for(int i=1;i<=n;i++){
            long long rem=(psum[i]%k+k)%k;
            if(mapy.find(rem)!=mapy.end()){
                cnt+=mapy[rem];
            }
            mapy[rem]++;
        }
        return cnt;
    }
};