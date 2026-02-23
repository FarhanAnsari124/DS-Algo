class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        if(n-k+1<(1<<k))return false;
        vector<int>vis((1<<k),0);
        int i=0;
        int num=0;
        int mask=(1<<k)-1;
        while(i<n){
            num=num<<1;
            num=(num&mask)|(s[i]-'0');
            if(i>=k-1){
                vis[num]=1;
            }
            i++;
        }
        for(auto x:vis){
            if(!x)return false;
        }
        return true;
    }
};