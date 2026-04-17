class Solution {
public:
    vector<string>ans;
    void solve(int n,int l,int r,string &e){
        if(e.size()==(2*n)){
            ans.push_back(e);
            return;
        }
        if(l<n){
            e+='(';
            solve(n,l+1,r,e);
            e.pop_back();
        }
        
        if(r<l){
            e+=')';
            solve(n,l,r+1,e);
            e.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string e;
        solve(n,0,0,e);
        return ans;
    }
};