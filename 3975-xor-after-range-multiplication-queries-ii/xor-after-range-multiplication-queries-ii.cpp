class Solution {
public:
    int mod=1000000007;
    int modpow(int base,int exp){
        int res=1;
        base=base%mod;
        while(exp>0){
            if(exp&1){
                res=(int)((1LL*res*base)%mod);
            }
            exp=exp/2;
            base=(int)((1LL*base*base)%mod);
        }
        return res%mod;
    }
    int modinv(int base){
        return modpow(base,mod-2);
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        int t=sqrt(n);
        vector<vector<vector<int>>> grp(t);
        for(int i=0;i<q.size();i++){
            int l=q[i][0];
            int r=q[i][1];
            int k=q[i][2];
            int v=q[i][3];
            int ind=l;
            if(k>=t){
                while(ind<=r){
                    nums[ind]=(int)((1LL*nums[ind]*v)%mod);
                    ind+=k;
                }
            }
            else{
                grp[k].push_back({l,r,v});
            }
        }
        vector<int> dif(n+t);
        for(int k=1;k<t;k++){
            if(grp[k].empty())continue;
            fill(dif.begin(),dif.end(),1);
            for(auto& arr:grp[k]){
                int l=arr[0];
                int r=arr[1];
                int v=arr[2];
                dif[l]=(int)(((1LL*dif[l]*v))%mod);
                int R=l+k+(((r-l)/k)*k);
                dif[R]=(int)((1LL*dif[R]*(modinv(v)))%mod);
            }
            for(int i=k;i<n;i++){
                dif[i]=(int)((1LL*dif[i]*dif[i-k])%mod);
            }
            for(int i=0;i<n;i++) nums[i]=(int)((1LL*nums[i]*dif[i])%mod);
        }
        
        int xr=nums[0];
        for(int i=1;i<nums.size();i++){
            xr=xr^nums[i];
        }
        return xr;
    }
};