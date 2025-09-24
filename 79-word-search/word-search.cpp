class Solution {
public:
    vector<pair<int,int>>dir={{0,-1},{0,1},{-1,0},{1,0}};
    bool solve(int i,int j,vector<vector<char>>&mat,string s,int k){
        if(k==s.size())return true;
        if(i<0||i>=mat.size()||j<0||j>=mat[0].size()){
            return false;
        }
        if(s[k]!=mat[i][j])return false;
        char ch=mat[i][j];
        mat[i][j]='$';
        bool orr=false;
        for(auto x:dir){
            orr|=solve(i+x.first,j+x.second,mat,s,k+1);
        }
        mat[i][j]=ch;
        return orr;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==1 && board[0].size()==1 && word.size()==1){
            return word[0]==board[0][0];
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};