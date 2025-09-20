class Solution {
public:
vector<vector<int>>ans;
    void solve(int indx,int n,vector<int>&arr,vector<int>&empty,int k){
        if(k==0){
            ans.push_back(empty);
            return;
            }
        if(indx>=n || k<0){
            return;
        }
        empty.push_back(arr[indx]);
        solve(indx,n,arr,empty,k-arr[indx]);
        empty.pop_back();
        solve(indx+1,n,arr,empty,k);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int>empty;
        int n=arr.size();
        solve(0,n,arr,empty,target);
        return ans;


        
    }
};