class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m=mat.size();
        int n=mat[0].size();
        int row=0;
        int col=n-1;
        while(row<m && col>=0){
            int mid=mat[row][col];
            if(mid==t)return true;
            else if(mid>t)col--;
            else row++;
        }
        return false;
    }
};