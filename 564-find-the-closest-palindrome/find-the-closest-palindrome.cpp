class Solution {
public:
    string get_palindrome(string s,bool even){

        if(even){
            string s1=s;
            reverse(s.begin(),s.end());
            return s1+s;
        }else{
            string s1=s;
            s=s.substr(0,s.size()-1);
            reverse(s.begin(),s.end());
            return s1+s;
        }

    }
    string nearestPalindromic(string n) {

        int size=n.size();
        bool even=size%2==0;
        vector<long long>v;
        string subst=n.substr(0,ceil((double)n.size()/2));

        string c1=get_palindrome(subst,even);
        if(c1!=n)v.push_back(stoll(c1));
        subst=to_string(stoll(subst)+1);
        string c2=get_palindrome(subst,even);
        v.push_back(stoll(c2));
        subst=to_string(stoll(subst)-2);
        string c3=get_palindrome(subst,even);
        v.push_back(stoll(c3));
        string c4=to_string((long long)pow(10,size)+1);
        v.push_back(stoll(c4));
        string c5=to_string((long long)pow(10,size-1)-1);
        v.push_back(stoll(c5));

        long long mini=1e15;
        int ansind=-1;
        sort(v.begin(),v.end());

        for(int i=0;i<v.size();i++){
            long long diff=abs(v[i]-stoll(n));
            if(diff<mini){
                mini=diff;
                ansind=i;
            }
        }

        return to_string(v[ansind]);
        
    }
};