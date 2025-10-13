class Solution {
public:
    bool isAnag(string s1,string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
    vector<string> removeAnagrams(vector<string>& s) {
        int i=1;
        int j=0;
        int n=s.size();
        while(i<n && j<n){
            while(i<n && isAnag(s[i],s[j])){
                s[i]="$";
                i++;
            }
            i++;
            j=i-1;
        }
        vector<string>v;
        for(auto x:s){
            if(x!="$")v.push_back(x);
        }
        return v;
    }
};