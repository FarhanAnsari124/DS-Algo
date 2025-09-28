class Solution {
public:
    bool is_smaller(string curr,string prev){
        int i=0,n=curr.size();
        while(i<n){
            while(i<n && curr[i]==prev[i]){
                i++;
            } 
            if(curr[i]>prev[i]){
                return false;
            }
            else return true;
        }
        return false;
    }
    string orderlyQueue(string s, int k) {
        if(s.size()==1)return s;
        string ans=s;
        if(k==1){
            for(int i=0;i<s.size()-1;i++){
                string temp=s.substr(1,s.size())+s.substr(0,1);
                if(is_smaller(temp,ans)){
                    ans=temp;
                }
                s=temp;
            }
        }else{
            sort(s.begin(),s.end());
            return s;
        }
        return ans;
    }
};