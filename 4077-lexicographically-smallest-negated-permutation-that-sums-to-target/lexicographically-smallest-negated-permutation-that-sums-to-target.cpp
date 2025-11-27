class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long sum=n*(n+1ll)/2ll;
        long long dif=(sum-target);
        vector<int>v;
        if(dif&1)return {};
        else if(sum<abs(target))return {};
        else {
            dif=dif/2;
            for(int i=n;i>=1;i--){
                if(dif>=i){
                    v.push_back(-i);
                    dif-=i;
                }else{
                    v.push_back(i);
                }
            }
        }
        sort(begin(v),end(v));
        return v;
    }
};