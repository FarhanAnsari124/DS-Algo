class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string>poftwo;
        for(int i=0;i<=30;i++){
            string t=to_string((int)pow(2,i));
            sort(t.begin(),t.end());
            // cout<<t;
            poftwo.insert(t);
        }
        string dup=to_string(n);
        // cout<<dup;
        sort(dup.begin(),dup.end());
        if(poftwo.find(dup)!=poftwo.end())return true;
        return false;
        
    }
};