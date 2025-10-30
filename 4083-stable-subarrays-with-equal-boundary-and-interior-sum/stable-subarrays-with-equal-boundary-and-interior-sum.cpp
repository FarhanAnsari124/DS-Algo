class Solution {
public:
    long long countStableSubarrays(vector<int>& arr) {
        int n=arr.size();
        map<pair<long long,long long>,long long>mapy;
        vector<long long>psum(n+1,0);
        for(int i=1;i<=n;i++){
            psum[i]=psum[i-1]+arr[i-1];
        }
        long long cnt=0;
        for(int i=1;i<=n;i++){
            pair<long long,long long> rem={psum[i]-2*arr[i-1],arr[i-1]};
            if(mapy.find(rem)!=mapy.end()){
                
                cnt+=mapy[rem];
            }
            mapy[{psum[i],arr[i-1]}]++;
            if(i<n && arr[i]==0 && arr[i-1]==0)cnt--;
        }
        return cnt;
    }
};