class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        set<int>rowToBeDeleted;
        set<int>colToBeDeleted;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    rowToBeDeleted.insert(i);
                    colToBeDeleted.insert(j);
                }
            }
        }
        for(auto x:rowToBeDeleted){
            int rowNo = x;
            for(int j=0;j<m;j++){
                mat[rowNo][j]=0;
            }
        }
        for(auto x:colToBeDeleted){
            int colNo = x;
            for(int i=0;i<n;i++){
                mat[i][colNo]=0;
            }
        }
    }
};