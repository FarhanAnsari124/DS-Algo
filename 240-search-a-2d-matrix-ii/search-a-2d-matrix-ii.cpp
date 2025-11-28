class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            if(mat[i][0]<=t && mat[i][n-1]>=t){
                auto it=upper_bound(mat[i].begin(),mat[i].end(),t);
                int ind=it-mat[i].begin();
                if(mat[i][ind-1]==t)return true;
            }
        }
        return false;
    }
};