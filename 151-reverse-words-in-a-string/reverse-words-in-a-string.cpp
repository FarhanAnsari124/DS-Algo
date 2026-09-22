class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        int n=s.size();
        int i=0;
        string ans;
        while(i<n){
            if(s[i] != ' '){
                st.push(s[i]);
            }else if(!st.empty()){
                if(!ans.empty())ans+=' ';
                while(!st.empty()){
                    ans+=st.top();st.pop();
                }
            }
            i++;
        }
        if(!st.empty()){
            if(!ans.empty())ans+=' ';
            while(!st.empty()){
                ans+=st.top();st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};