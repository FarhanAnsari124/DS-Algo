class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int target,int k,vector<int>empty){
        if(k==0 && target==0){
            ans.push_back(empty);
            return;
        }
        if(!k || i>9)return;
        if(target-i>=0){
            empty.push_back(i);
            solve(i+1,target-i,k-1,empty);
            empty.pop_back();
        }
        solve(i+1,target,k,empty);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>empty;
        solve(1,n,k,empty);
        return ans;
    }
};