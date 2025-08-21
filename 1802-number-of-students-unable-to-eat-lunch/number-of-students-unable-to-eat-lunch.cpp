class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sw) {
        int n=stud.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            st.push(sw[i]);
        }
       int cnt_o=0;
        int cnt_i=0;
        for(int i=0;i<n;i++){
            if(stud[i]==1)cnt_i++;
            else cnt_o++;
        }
        while(!st.empty()){
            int t=st.top();
            if(t==1 && cnt_i>0){
                cnt_i--;
                st.pop();
            }
            else if(t==0 && cnt_o>0){
                cnt_o--;
                st.pop();
            }else{
                break;
            }
        }
        return cnt_i+cnt_o;
    }
};