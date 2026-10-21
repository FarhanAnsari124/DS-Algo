class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int>mins(n);
        mins[0]=nums[0];
        for(int i=1;i<n;i++){
            mins[i]=min(mins[i-1],nums[i]);
        }
        stack<int>st;
        for(int i=n-1;i>0;i--){
            int c=nums[i];
            while(!st.empty() && st.top()<=mins[i-1]){
                st.pop();
            }
            if(!st.empty() && c>st.top() && st.top()>mins[i-1])return true;
            
            st.push(c);
        }
        return false;
        
    }
};