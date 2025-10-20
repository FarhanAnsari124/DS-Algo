class Solution {
public:
    int numberOfSubarrays(vector<int>& arr, int k) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]%2==0)arr[i]=0;
            else arr[i]=1;
        }
        // for(auto x:arr)cout<<x<<" ";
        unordered_map<int,int>mapy;
        vector<int>psum(n+1,0);
        for(int i=1;i<=n;i++){
            psum[i]=psum[i-1]+arr[i-1];
        }
        // for(auto x:psum)cout<<x<<" ";
        int cnt=0;
        for(int i=0;i<=n;i++){
            int rem=psum[i]-k;
            if(mapy.find(rem)!=mapy.end()){
                cnt+=mapy[rem];
            }
            mapy[psum[i]]++;
        }
        return cnt;
    }
};