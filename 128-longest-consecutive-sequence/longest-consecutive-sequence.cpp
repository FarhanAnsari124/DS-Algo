class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int maxi=0;

        for(auto x:st){
            int num=x;
            if(st.find(num-1)!=st.end()){
                continue;
            }else{
                int cnt=1;
                while(true){
                    if(st.find(num+1)!=st.end()){
                        cnt++;
                        num=num+1;
                    }else break;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};