class Solution {
public:
    int findFinalValue(vector<int>& nums, int org){
        set<int>st(nums.begin(),nums.end());
        while(true){
            if(st.find(org)==st.end()){
                break;
            }
            else org*=2;
        }
        return org;
    }
};