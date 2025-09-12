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
        vector<vector<int>>ans(2);
        for(auto x:mapy){
            if(x.second==1)ans[1].push_back(x.first);
        }
        for(auto x:all){
            if(mapy.find(x)==mapy.end()){
                ans[0].push_back(x);
            }
        }
        return ans;
    }
};