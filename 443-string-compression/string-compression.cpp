class Solution {
public:
    int compress(vector<char>& s) {
       int len=1;
       int i=1;
       int n=s.size();
       vector<char>ans;
       while(i<n){
            if(s[i]==s[i-1]){
                len++;
            }else{
                if(len>1){
                    ans.push_back(s[i-1]);
                    string l=to_string(len);
                    for(int i=0;i<l.size();i++){
                        ans.push_back(l[i]);
                    }
                }else{
                    ans.push_back(s[i-1]);
                }
                len=1;
            }
            i++;
        }
        if(len>=1){
            ans.push_back(s[i-1]);
            if(len>1){
                string l=to_string(len);
                for(int i=0;i<l.size();i++){
                    ans.push_back(l[i]);
                }
                // cout<<len;
            }
        }
        for(int i=0;i<ans.size();i++){
            s[i]=ans[i];
        }
        return ans.size();
    }
};