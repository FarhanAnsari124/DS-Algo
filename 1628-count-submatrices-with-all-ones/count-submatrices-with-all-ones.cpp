class Solution {
public:
    int ArrayCount(vector<int>&temp){
        int main=0;
        int cnt=0;
            for(int j=0;j<temp.size();j++){
                if(temp[j]==1){
                    cnt++;
                }else{
                    main+=(cnt*(cnt+1))/2;
                    cnt=0;
                }
            }
        if(cnt!=0)main+=(cnt*(cnt+1))/2;
        return main;
    }
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<int>>ans;
        int m=mat.size();
        int n=mat[0].size();
        int result=0;
        for(int sr=0;sr<m;sr++){
            vector<int>temp(n,1);
            for(int er=sr;er<m;er++){
                for(int j=0;j<n;j++){
                    temp[j]=temp[j]&mat[er][j];
                }
                result+=ArrayCount(temp);
            }
        }
        return result;
        
    }
};