class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(mat[mid/n][mid%n]==t)return true;
            else if(mat[mid/n][mid%n]>t)high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};