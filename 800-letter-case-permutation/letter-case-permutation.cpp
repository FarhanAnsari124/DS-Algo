class Solution {
public:
    vector<string>ans;
    void solve(int i,int n,string &s,string e){
        if(i==n){
            ans.push_back(e);
            return;
        }
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            char ch=tolower(s[i]);
            solve(i+1,n,s,e+ch);
            char nch=toupper(s[i]);
            solve(i+1,n,s,e+nch);
        }else{
            solve(i+1,n,s,e+s[i]);
        }
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        string e;
        solve(0,n,s,e);
        return ans;
    }
};