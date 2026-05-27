class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>total_freq;
        for(auto x:word)total_freq[x]++;
        unordered_map<char,int>running_freq;
        int cnt=0;
        for(auto x:word){
            if(isupper(x) && !running_freq[x] && total_freq[tolower(x)] && running_freq[tolower(x)]==total_freq[tolower(x)]){
                cnt++;
            }

            running_freq[x]++;
        }
        return cnt;
    }
};