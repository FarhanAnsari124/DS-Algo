class Solution {
public:
    char nextChar(char c) {
        return (c - 'a' + 1) % 26 + 'a';
    }
    long long countPairs(vector<string>& words) {
        long long cnt=0;
        unordered_map<string,int>mapy;
        int n=words.size();
        for(int i=0;i<n;i++){
            string s=words[i];
            string rem;
            for(auto x:s){
                rem+=nextChar(x);
            }
            while(rem!=s){
                if(mapy.find(rem)!=mapy.end()){
                    cnt+=mapy[rem];
                }
                for(int i=0;i<rem.size();i++){
                    rem[i]=nextChar(rem[i]);
                }
            }
            if(mapy.find(rem)!=mapy.end()){
                cnt+=mapy[rem];
            }
            mapy[s]++;
        }
        return cnt;
    }
};