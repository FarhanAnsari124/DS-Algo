class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string pre=strs[0];
        int n=strs.size();
        for(int i=1;i<n;i++){
            string temp=strs[i];
            string newpre;
            for(int j=0;j<min(temp.size(),pre.size());j++){
                if(pre[j]==temp[j]){
                    newpre+=temp[j];
                }else{
                    break;
                }
            }
            pre=newpre;
        }
        return pre; 
    }
};