class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& dp) {
        int n=dp.size();
        for(int i=1;i<n;i++){
        vector<int>temp;
        int row=0;
        int col=i;
        while(row<n && col<n){
            temp.push_back(dp[row][col]);
            row++;
            col++;
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        row=0;
        col=i;
        while(row<n && col<n){
            dp[row][col]=temp.back();
            temp.pop_back();
            row++;
            col++;
        }
    }
    for(int i=0;i<n;i++){
        vector<int>temp;
        int row=i;
        int col=0;
        while(row<n && col<n){
            temp.push_back(dp[row][col]);
            row++;
            col++;
        }
        sort(temp.begin(),temp.end());
        row=i;
        col=0;
        while(row<n && col<n){
            dp[row][col]=temp.back();
            temp.pop_back();
            row++;
            col++;
        }
    }
    return dp;
    }
};