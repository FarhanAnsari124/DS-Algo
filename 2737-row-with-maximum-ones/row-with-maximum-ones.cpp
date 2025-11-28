class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int ind=0;
        int maxi=0;
        for(int i=0;i<m;i++){
            sort(mat[i].begin(),mat[i].end());
            auto it=upper_bound(mat[i].begin(),mat[i].end(),0);
            int st=it-mat[i].begin();
            if(n-st>maxi){
                maxi=n-st;
                ind=i;
            }
        }
        return {ind,maxi};
    }
};