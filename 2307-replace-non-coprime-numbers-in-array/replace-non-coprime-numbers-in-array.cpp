class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>st;
        int n=nums.size();
        for(auto num:nums){
            while(!st.empty()){
                int prev=st.back();
                int gcdd=gcd(st.back(),num);
                if(gcdd==1)break;
                st.pop_back();
                long long lcm=prev/gcdd*num;
                num=lcm;
            }
            st.push_back(num);
        }
        return st;
    }
};