class Solution {
public:
    int finalValueAfterOperations(vector<string>& opr) {
        int ans=0;
        for(auto x:opr){
            if(x=="--X" || x=="X--"){
                ans--;
            }else ans++;
        }
        return ans;
    }
};