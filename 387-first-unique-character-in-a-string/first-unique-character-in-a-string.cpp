class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mapy;
        int idx=0;
        for(auto x:s){
            mapy[x]++;
            while(idx<s.size() && mapy[s[idx]]>1){
                idx++;
                if(idx==s.size())return -1;
            }
        }
        return idx;
    }
};