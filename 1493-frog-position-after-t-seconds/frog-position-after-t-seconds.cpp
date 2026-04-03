class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>>adj(n+1);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<pair<pair<int,int>,double>>q;
        vector<int>vis(n+1,0);
        q.push({{1,0},1.0});
        vis[1]=1;
        if(target==1 && adj[1].size()==0)return 1.0;
        else if(target ==1 && adj[1].size()>0)return 0;
        double ans=0;
        while(!q.empty()){
            auto top=q.front();q.pop();
            int num=top.first.first;
            int dist=top.first.second;
            double prob=top.second;
            for(auto x:adj[num]){
                if(!vis[x]){
                    vis[x]=1;
                    double nprob=0;
                    if(num==1){
                        nprob=prob*((double)1/(adj[num].size()));
                    }
                    else nprob=prob*((double)1/(adj[num].size()-1));
                    if(x==target && t==(dist+1)){
                        ans=nprob;
                        return ans;
                    }else if(x==target && t>(dist+1) && adj[x].size()<=1){
                        ans=nprob;
                        return ans;
                    }else if(x==target && t>(dist+1) && adj[x].size()>1){
                        return 0;
                    }else if(x==target && t<(dist+1)){
                        return 0;
                    }
                    q.push({{x,dist+1},nprob});
                }
            }
        }
        return ans;
    }
};