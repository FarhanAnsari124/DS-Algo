class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int>mapy;
        int n=arr.size();
        int cnt=0;
        vector<int>psum(n+1,0);
        mapy[0]=1;
        for(int i=1;i<=n;i++)psum[i]=psum[i-1]+arr[i-1];
        for(int i=1;i<=n;i++){
            int rem=psum[i]-k;
            if(mapy.find(rem)!=mapy.end()){
                cnt+=mapy[rem];
            }
            mapy[psum[i]]++;
        }
        return cnt;
    }
};