class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mapy;
        int n=s.size();
        int idx=0;
        for(int i=0;i<n;i++){
            mapy[s[i]]++;
            while(idx<n && mapy[s[idx]]>1){
                idx++;
                if(idx==n)return -1;
            }
        }
        return idx;
    }
};