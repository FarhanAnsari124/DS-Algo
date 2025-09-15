class Solution {
public:
    int canBeTypedWords(string text, string b) {
        set<char>s;
        for(auto x:b){
            s.insert(x);
        }
        int n=text.size();
        bool br=false;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(text[i]==' '){
                if(br){
                    br=false;
                }else{
                    cnt++;
                }
            }
            else if(s.find(text[i])!=s.end()){
                br=true;
            }
        }
        if(!br)cnt++;
        return cnt;
    }
};