class Solution {
public:
    map<char,char>mapy={
        {'2','5'},
        {'6','9'},
        {'5','2'},
        {'9','6'},
        {'1','1'},
        {'0','0'},
        {'8','8'}
    };
    bool valid(int n,int limit){
        string s=to_string(n);
        for(int i=0;i<s.size();i++){
            if(mapy.find(s[i])!=mapy.end()){
                s[i]=mapy[s[i]];
            }else {
                return false;
            }
        }
        int num=stoi(s);
        if(num!=n){
            // cout<<n<<":"<<num<<endl;
            return true;
        }
        return false;
    }
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(valid(i,n))cnt++;
        }
        return cnt;
    }
};