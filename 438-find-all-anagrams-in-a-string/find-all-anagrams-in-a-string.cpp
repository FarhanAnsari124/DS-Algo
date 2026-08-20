class Solution {
public:
    int checkanagram(string &s,int l,int r,vector<int>&frp){
        vector<int>frs(26,0);
        for(int i=l;i<=r;i++)frs[s[i]-97]++;
        for(int i=0;i<26;i++)
            if(frs[i]!=frp[i])
                return 0;
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>frp(26,0);
        for(auto x:p)frp[x-97]++;
        int l=0,r=0;
        int n=s.size();
        vector<int>v;
        while(r<n){
            while(r-l+1 > p.size()){
                l++;
            }
            if(checkanagram(s,l,r,frp))
                v.push_back(l);
            r++;
        }
        return v;
    }
};