class Solution {
public:
    int countCollisions(string s) {
        int n=s.size();
        int sum=0;
        int temp=-2;
        int r=0,l=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                if(temp==1){
                    sum+=r+1;
                    temp=0;
                }else if(temp==0){
                    sum+=1;temp=0;
                }
                r=0;
            }else if(s[i]=='R'){
                temp=1;
                r++;
            }else{
                if(temp==1){
                    sum+=r;temp=0;
                }else{
                    temp=0;
                }
                r=0;
            }
        }
        return sum;
    }
};