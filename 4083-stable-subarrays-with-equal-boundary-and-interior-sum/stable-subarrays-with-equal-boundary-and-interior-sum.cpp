class Solution {
public:
    using ll = long long;
    long long countStableSubarrays(vector<int>& arr) {
        ll n=arr.size();
        map<pair<ll,ll>,ll>mapy;
        vector<ll>psum(n+1,0);
        for(ll i=1;i<=n;i++){
            psum[i]=psum[i-1]+arr[i-1];
        }
        ll cnt=0;
        for(ll i=1;i<=n;i++){
            pair<ll,ll> rem={psum[i]-2*arr[i-1],arr[i-1]};
            if(mapy.find(rem)!=mapy.end()){
                cnt+=mapy[rem];
            }
            mapy[{psum[i],arr[i-1]}]++;
            if(i<n && arr[i]==0 && arr[i-1]==0)cnt--;
        }
        return cnt;
    }
};