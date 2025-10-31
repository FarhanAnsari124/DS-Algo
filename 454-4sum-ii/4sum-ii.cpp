class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        unordered_map<int,int>mapy;
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mapy[c[i]+d[j]]++;
            }
        }
        long long cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int rem=-(a[i]+b[j]);
                if(mapy.find(rem)!=mapy.end()){
                    cnt+=mapy[rem];
                }
            }
        }
        return cnt;
    }
};