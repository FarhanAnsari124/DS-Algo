class Solution {
public:
    bool doesAliceWin(string s) {
      set<char>vowels={'a','e','i','o','u'};
      int cnt_of_vowels=0;
      for(auto x:s){
        if(vowels.find(x)!=vowels.end()){
            cnt_of_vowels++;
        }
      }
      if(cnt_of_vowels)return true;
      return false;
    }
};