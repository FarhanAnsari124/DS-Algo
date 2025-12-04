class Solution {
public:
    bool solve(string &s,int i,int j){
        if(i>=j)return true;
        if(s[i]==s[j]){
            return solve(s,i+1,j-1);
        }else{
            return false;
        }
    }
    string longestPalindrome(string s) {
        int maxl=-1;
        int st=-1;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)){
                    if(maxl<j-i+1){
                        maxl=j-i+1;
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,maxl);
    }
};