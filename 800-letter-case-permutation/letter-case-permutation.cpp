class Solution {
public:
    vector<string>ans;
    void solve(int i,int n,string &s,string &e){
        if(i==n){
            ans.push_back(e);
            return;
        }
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            e+=tolower(s[i]);
            solve(i+1,n,s,e);
            e.pop_back();
            e+=toupper(s[i]);
            solve(i+1,n,s,e);
            e.pop_back();
        }else{
            e.push_back(s[i]);
            solve(i+1,n,s,e);
            e.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        string e;
        solve(0,n,s,e);
        return ans;
    }
};