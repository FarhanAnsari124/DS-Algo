class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int cnt=0;
        for(auto x:s){
            if(x=='(')st.push(x);
            else if(!st.empty()) st.pop();
            else cnt++;
        }
        return cnt+=st.size();
    }
};