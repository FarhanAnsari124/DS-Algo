class Solution {
public:
    int dot_count(string v){
        int cnt=0;
        for(auto x:v){
            if(x=='.')cnt++;
        }
        return cnt;
    }
    int compareVersion(string v1, string v2) {
        int dots1=dot_count(v1);
        int dots2=dot_count(v2);
        if(dots1>dots2){
            for(int i=0;i<(dots1-dots2);i++){
                v2+='.';
                v2+='0';
            }
        }else if(dots1<dots2){
            for(int i=0;i<(dots2-dots1);i++){
                v1+='.';
                v1+='0';
            }
        }
        cout<<v2;
        int start_l=0;
        int start_r=0;
        int left=0,right=0;
        while(left<v1.size() && right<v2.size()){
            while( left<v1.size() && v1[left]!='.'){
                left++;
            }
            int end_l=left;
            string sub1=v1.substr(start_l,end_l-start_l);
            start_l=left+1;
            while(right<v2.size() && v2[right]!='.'){
                right++;
            }
            int end_r=right;
            string sub2=v2.substr(start_r,end_r-start_r);
            start_r=right+1;
            if(stoll(sub1)>stoll(sub2)){
                return 1;
            }else if(stoll(sub1)<stoll(sub2)){
                return -1;
            }
            left++;
            right++;
        }
        return 0;

    }
};