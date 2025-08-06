class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l=0;
        int r=0;
        int n=g.size();
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int cnt=0;
        int m=s.size();
        if(m==0)return 0;
        while(l<n){
            if(r<m && g[l]>s[r]){
                r++;
            }
            if(r==m)break;
            if(g[l]<=s[r]){
                cnt++;
                l++;
                r++;
            }
        }
        return cnt;
    }
};