class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        string ans;
        reverse(s.begin(),s.end());
        while(i<n){
            if(s[i]==' '){
                i++;
            }
            else{
                int j=i;
                string word;
                while(j<n && s[j]!=' '){
                    word+=s[j];
                    j++;
                }
                if(!ans.empty())ans+=' ';
                reverse(word.begin(),word.end());
                ans+=word;
                i=j;
            }
        }

        return ans;
    }
};