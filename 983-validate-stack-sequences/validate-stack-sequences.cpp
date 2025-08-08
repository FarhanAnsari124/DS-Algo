class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int r=0;
        for(int i=0;i<pushed.size();i++){
            if(pushed[i]==popped[r]){
                r++;
                while(!st.empty() && st.top()==popped[r]){
                    st.pop();
                    r++;
                }
            }
            else{
                st.push(pushed[i]);
            }
        }
        for(int i=r;i<popped.size();i++){
            if(popped[i]!=st.top()){
                return false;
            }else{
                st.pop();
            }
        }
        return true;
        
    }
};