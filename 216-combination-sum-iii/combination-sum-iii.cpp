class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int &sum,int target,int k,int size,vector<int>empty){
        if(empty.size()==size && sum==target){
            ans.push_back(empty);
            return;
        }
        if(!k || i>9)return;
        if(sum+i<=target){
            empty.push_back(i);
            sum+=i;
            solve(i+1,sum,target,k-1,size,empty);
            sum-=i;
            empty.pop_back();
        }
        solve(i+1,sum,target,k,size,empty);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>empty;
        int sum=0;
        solve(1,sum,n,k,k,empty);
        return ans;
        
    }
};