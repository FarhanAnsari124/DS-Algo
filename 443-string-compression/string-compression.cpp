class Solution {
public:
    int compress(vector<char>& s) {
        int cnt=0;
        char curr_char=s[0];
        int n=s.size();
        if(n==1)return n;
        int i=0;
        int indx=0;
        while(i<n){
            if(s[i]==curr_char){
                cnt++;
                i++;
            }else{
                s[indx]=curr_char;
                indx++;
                if(cnt>1){
                    string l=to_string(cnt);
                    for(auto x:l){
                        s[indx]=x;
                        indx++;
                    }
                }
                cnt=0;
                curr_char=s[i];
                
            }
        }
        if(cnt>=1){
            s[indx]=curr_char;
            indx++;
            if(cnt>1){
                string l=to_string(cnt);
                for(auto x:l){
                    s[indx]=x;
                    indx++;
                }
            }
        }
        return indx;

    }
};