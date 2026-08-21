class Solution {
public:
    string decodeString(string s) {
        stack<pair<int,string>>st;
        int curr_no=0;
        string curr_str = "";
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(isdigit(s[i])){
                curr_no = curr_no*10+ s[i]-'0';
            }else if(ch=='['){
                st.push({curr_no,curr_str});
                curr_no=0;
                curr_str="";
            }else if(ch==']'){
                int repeat=st.top().first;
                string prev_str=st.top().second;
                st.pop();
                string temp;
                while(repeat--)temp+=curr_str;
                curr_str = prev_str + temp;
            }else{
                curr_str += ch; 
            }
        }
        return curr_str;
    }
};