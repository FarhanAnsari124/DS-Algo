class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>=s.size())return false;
        vector<int>vis((1<<k),0);
        int i=0;int j=0;
        int n=s.size();
        int num=0;
        while(i<n && j<n){
            num=num<<1;
            num=num|(s[j]-'0');
            if((j-i+1)>k){
                if(s[i]=='1') num=num^(1<<k);
                i++;
            }
            if(num!=0)vis[num]=1;
            else if((j-i+1)==k)vis[num]=1;
            j++;
        }
        for(auto x:vis){
            if(!x)return false;
        }
        return true;
    }
};