class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>vowels;
        unordered_map<char,int>cons;
        for(auto x:s){
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                vowels[x]++;
            }else{
                cons[x]++;
            }
        }
        int maxivow=0;
        int maxicons=0;
        for(auto x:vowels){
            maxivow=max(maxivow,x.second);
        }
        for(auto x:cons){
            maxicons=max(maxicons,x.second);
        }
        return maxivow+maxicons;
    }
};