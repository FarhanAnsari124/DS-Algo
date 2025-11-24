class Solution {
public:
    const int MOD=1000000007;

    long long modpow(long long a,long long b){
        long long r=1;
        while(b){
            if(b&1) r=r*a%MOD;
            a=a*a%MOD;
            b>>=1;
        }
        return r;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int n=s.size();
        vector<long long> psum(n+1,0);
        vector<long long> v(n+1,0);
        vector<long long> nz(n+1,0);

        for(int i=1;i<=n;i++){
            int d=s[i-1]-'0';
            if(d!=0){
                v[i]=(v[i-1]*10+d)%MOD;
            }else v[i]=v[i-1];
            psum[i]=psum[i-1]+d;
            nz[i]=nz[i-1]+(d!=0);
        }

        vector<int> ans;

        for(auto x:q){
            int r=x[1]+1;
            int l=x[0]+1;
            long long sum=psum[r]-psum[l-1];
            sum=(sum%MOD+MOD)%MOD;

            if(l==1){
                ans.push_back(sum*v[r]%MOD);
            }else{
                long long cnt=nz[r]-nz[l-1];
                long long p=modpow(10,cnt);
                long long right=v[r];
                long long left=v[l-1]*p%MOD;
                long long mul=(right-left+MOD)%MOD;
                ans.push_back(sum*mul%MOD);
            }
        }

        return ans;
    }
};
