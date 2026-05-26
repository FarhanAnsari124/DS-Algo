class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>s(word.begin(),word.end());
        int cnt=0;
        for(auto x:s){
            if(isupper(x) && s.count(tolower(x)))cnt++;
        }
        return cnt;
    }
};