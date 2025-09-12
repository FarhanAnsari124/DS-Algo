class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool doesAliceWin(string s) {
      int cnt_of_vowels=0;
      for(char &c:s){
        if(is_vowel(c)){
            cnt_of_vowels++;
        }
      }
      return cnt_of_vowels>0;
    }
};