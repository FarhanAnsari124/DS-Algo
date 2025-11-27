class Solution {
public:
    long long wavy(int num){
        string s=to_string(num);
        int n=s.size();
        long long cnt=0;
        for(int i=1;i<n-1;i++){
            int prev=s[i-1]-'0';
            int curr=s[i]-'0';
            int next=s[i+1]-'0';
            if(curr>prev && curr>next){
                cnt++;
            }else if(curr<prev && curr<next){
                cnt++;
            }
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            ans+=wavy(i);
        }
        return ans;
    }
};