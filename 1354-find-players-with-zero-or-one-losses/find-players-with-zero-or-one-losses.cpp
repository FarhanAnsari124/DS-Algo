class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mapy;
        set<int>all;
        for(auto x:matches){
            all.insert(x[0]);
            all.insert(x[1]);
            mapy[x[1]]++;
        }
        vector<vector<int>>ans;
        vector<int>oneloss;
        vector<int>zeroloss;
        for(auto x:mapy){
            if(x.second==1)oneloss.push_back(x.first);
        }
        for(auto x:all){
            if(mapy.find(x)==mapy.end()){
                zeroloss.push_back(x);
            }
        }
        ans.push_back(zeroloss);
        ans.push_back(oneloss);
        return ans;
    }
};