class Solution {
public:
    string makeGood(string s) {
        string st;
        int n=s.size();
        int i=0;
        while(i<n){
            if(!st.empty() && abs(st.back()-s[i])==32){
                st.pop_back();
            }
            else{
                st+=s[i];
            }
            i++;
        }
        return st;
    }
};