class Solution {
public:
    int solve(int i,int j,string &s,int q,int n){
        if(j>=n || i<0 || j<0 || i>=n || i>j){
            return 0;
        } 
        unordered_map<char,int>mapy;
        for(int k=i;k<=j;k++){
            mapy[s[k]]++;
        }
        int maxi=0;
        bool flag=false;
        for(auto x:mapy){
            if(x.second>=q)flag=true;
        }
        if(!flag)return 0;
        for(int k=i;k<=j;k++){
            if(mapy[s[k]]<q){
                return maxi=max(solve(i,k-1,s,q,n),solve(k+1,j,s,q,n));
            }
        }
        return j-i+1;
    }
    int longestSubstring(string s, int k) {
        int n=s.size();
        return solve(0,s.size()-1,s,k,n);
    }
};