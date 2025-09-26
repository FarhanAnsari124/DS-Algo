class Solution {
public:
    vector<int>makeLPS(string &needle,vector<int>&LPS,int &m){
        int len=0;
        int i=1;
        while(i<m){
            if(needle[i]==needle[len]){
                len++;
                LPS[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=LPS[len-1];
                }else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
        return LPS;
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int>LPS(m,0);
        LPS[0]=0;
        makeLPS(needle,LPS,m);
        vector<int>res;
        int i=0;
        int j=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m){
                res.push_back(i-m);
                j=LPS[j-1];
            }
            else if(haystack[i]!=needle[j]){
                if(j!=0)j=LPS[j-1];
                else i++;
            }
        }
        return res.size()>0?res[0]:-1;
    }
};