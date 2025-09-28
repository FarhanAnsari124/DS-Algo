class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int n=s.size();
        int i=0;
        while(i<n){
            if(!st.empty() && abs(st.top()-s[i])==32){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};