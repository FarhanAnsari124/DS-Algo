class Solution {
public:
    int bestClosingTime(string c) {
       int s=0;
       int n=c.size();
       for(auto x:c){
        if(x=='Y')s++;
       }
       int ans=s;
       int ind=0;
       for(int i=1;i<=n;i++){
            if(c[i-1]=='Y'){
                s--;
                if(s<ans){
                    ans=s;
                    ind=i;
                }
            }else{
                s++;
            }
       }
       return ind; 
    }
};