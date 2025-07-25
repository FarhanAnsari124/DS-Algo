class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string f;
        string sec;
        if(x>=y){
            f="ab";
            sec="ba";
        }
        else{
            f="ba";
            sec="ab";
        }
        string st;
        long long p=0;
        long long n=s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() && s[i]==f[1] && st.back()==f[0]){
                if(f[0]=='a')p+=x;
                else p+=y;
                st.pop_back();
            }
            else st.push_back(s[i]);
        }
        s=st;
        st.clear();
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]==sec[1] && st.back()==sec[0]){
                if(sec[0]=='a')p+=x;
                else p+=y;
                st.pop_back();
            }
            else st.push_back(s[i]);
        }
        return p;
    }
};