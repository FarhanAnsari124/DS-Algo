class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        int i1=0,i2=0,j=0,k=0;
        while(i1<n && i2<m){
            if(word1[i1][j]!=word2[i2][k]){
                return false;
            }
            if(j==word1[i1].size()-1){
                i1++;
                j=0;
            }else j++;
            if(k==word2[i2].size()-1){
                i2++;
                k=0;
            }else k++;
        }
        return (i1==n && i2==m);
    }
};