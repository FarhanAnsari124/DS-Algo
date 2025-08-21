class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<int>>ans;
        int m=mat.size();
        int n=mat[0].size();
        for(int sr=0;sr<m;sr++){
            for(int er=sr;er<m;er++){
                vector<int>temp;
                for(int j=0;j<n;j++){
                    int t=1;
                    for(int i=sr;i<=er;i++){
                        t=t&mat[i][j];
                    }
                    temp.push_back(t);
                }
                ans.push_back(temp);
            }
        }
        int main=0;
        for(int i=0;i<ans.size();i++){
            int cnt=0;
            for(int j=0;j<ans[0].size();j++){
                if(ans[i][j]==1){
                    cnt++;
                }else{
                    main+=(cnt*(cnt+1))/2;
                    cnt=0;
                }
            }
            if(cnt!=0)main+=(cnt*(cnt+1))/2;
        }
        return main;
    }
};