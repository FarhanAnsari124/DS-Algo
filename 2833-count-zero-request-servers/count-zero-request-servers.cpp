class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int y,
                             vector<int>& q) {
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int Q = q.size();
        vector<vector<int>> sq(Q,vector<int>(2));
        for (int i = 0; i < Q; i++) {
            sq[i][0] = i;
            sq[i][1] = q[i];
        }
        sort(sq.begin(), sq.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int start=0,end=0;
        unordered_map<int,int>mapy;
        vector<int>ans(Q);
        for(auto x:sq){
            int i=x[0];
            int min=x[1]-y;
            int max=x[1];
            while(end<logs.size() && max>=logs[end][1]){
                mapy[logs[end][0]]++;
                end++;
            }
            while(start<end && min>logs[start][1]){
                if(mapy[logs[start][0]]==1){
                    mapy.erase(logs[start][0]);
                }else mapy[logs[start][0]]--;
                start++;
            }
            ans[i]=n-mapy.size();
        }
        return ans;
    }
};