class Solution {
public:
    int numSteps(string s) {
        int st=0;
        while(s!="1"){
            if(s.back()=='1'){
                int c=0;
                for(int i=s.size()-1;i>=0;i--){
                    if(s[i]=='1'){
                        s[i]='0';
                        c=1;
                    }else{
                        s[i]='1';
                        c=0;
                        break;
                    }
                }
                if(c==1){
                    s="1"+s;
                }
            }else {
                s.pop_back();
            }
            st++;
        }
        return st;
    }
};