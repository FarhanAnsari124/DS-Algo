class Solution {
public:
    unordered_map<int,string>phone;
    vector<string>ans;
    void make_tele_btn(){
        int no=2;
        int i=97;
        while(i<(97+26)){
            string temp;
            for(int j=i;j<i+3;j++){
                temp+=(char)j;
            }
            if(no==7 || no ==9){
                temp+=(char)i+3;
                i+=4;
            }else{
                i+=3;
            }
            phone[no]=temp;
            no++;
        }
    }
    void solve(int i,int n,string empty,string&d){
        if(i==n){
            ans.push_back(empty);
            return;
        }
        string t;
        t+=d[i];
        for(auto x:phone[stoi(t)]){
            solve(i+1,n,empty+x,d);
        }
    }
    vector<string> letterCombinations(string d) {
        make_tele_btn();
        if(!d.size())return {};
        int n=d.size();
        string empty;
        solve(0,n,empty,d);
        return ans;
    }
};