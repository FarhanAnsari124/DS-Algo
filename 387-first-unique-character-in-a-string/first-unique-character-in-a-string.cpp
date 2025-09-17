class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mapy;
        for(auto x:s){
            mapy[x]++;
        }
        for(int i=0;i<s.size();i++){
            if(mapy[s[i]]==1)return i;
        }
        return -1;
    }
};