class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int>mapy;
       
       int maxi=-1e9;
       int n=s.size();
       if(n==0)return 0;
       int i=0;
       int j=0;
       while(i<n){
        while(mapy[s[i]]>=1){
            mapy[s[j]]--;
            j++;
        }
        mapy[s[i]]++;
        maxi=max(maxi,i-j+1);
        i++;
       }
       return maxi;
    }
};