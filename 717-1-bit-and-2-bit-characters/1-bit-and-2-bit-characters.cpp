class Solution {
public:
    bool isOneBitCharacter(vector<int>& b) {
        int n=b.size();
        bool flag=false;
        int i=1;
        while(i<n){
            if(b[i-1]==1 && (b[i]==0 || b[i]==1)){
                flag=true;
                i+=2;
            }else{
                flag=false;
                i+=1;
            }
        }
        if(i==n && flag)return flag;
        return !flag;
    }
};