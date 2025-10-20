class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        if(s.empty() || t.empty())return 0;
        unordered_map<char,int>mapy;
        unordered_map<char,int>mapy2;
        for(auto x:s){
            mapy[x]++;
        }
        for(auto x:t){
            mapy2[x]++;
        }
        int ans=1e9;
        for(auto &x:t){
            if(mapy.find(x)!=mapy.end()){
                ans=min(mapy[x]/mapy2[x],ans);
            }else ans=0;
        }
        if(ans==1e9)return 0;
        else return ans;
    }
};