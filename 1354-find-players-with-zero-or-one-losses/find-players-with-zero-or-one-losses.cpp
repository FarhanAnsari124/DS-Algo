class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mapy;
        for(auto x:matches){
            if(mapy.find(x[0])==mapy.end()){
                mapy.insert({x[0],0});
            }
            mapy[x[1]]++;
        }
        vector<vector<int>>ans(2);
        for(auto x:mapy){
            if(x.second==1)ans[1].push_back(x.first);
            else if(x.second==0)ans[0].push_back(x.first);
        }
        return ans;
    }
};