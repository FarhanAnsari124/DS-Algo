class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mapy;
        for(auto x:matches){
            int winner=x[0];
            int losser=x[1];
            if(mapy.find(winner)==mapy.end()){
                mapy.insert({winner,0});
            }
            mapy[losser]++;
        }
        vector<vector<int>>ans(2);
        for(auto x:mapy){
            if(x.second==1)ans[1].push_back(x.first);
            else if(x.second==0)ans[0].push_back(x.first);
        }
        return ans;
    }
};