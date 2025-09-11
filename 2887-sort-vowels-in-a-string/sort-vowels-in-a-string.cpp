class Solution {
public:
    string sortVowels(string s) {
        string vowels;
        set<char>evowel={'a','e','i','o','u','A','E','I','O','U'};
        for(auto x:s){
            if(evowel.find(x)!=evowel.end()){
                vowels+=x;
            }
        }
        sort(vowels.begin(),vowels.end());
        cout<<vowels;
        int k=0;
        for(int i=0;i<s.size();i++){
            if(evowel.find(s[i])!=evowel.end()){
                s[i]=vowels[k];
                k++;
            }
        }
        return s;
    }
};