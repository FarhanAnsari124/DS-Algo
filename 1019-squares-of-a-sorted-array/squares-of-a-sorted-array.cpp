class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        vector<int>ans;
        int n=arr.size();
        int i=0;
        while(i<n && arr[i]<0){
            i++;
        }
        int j=i-1;
        while(j>=0 && i<n){
            if(abs(arr[j])>arr[i]){
                ans.push_back((arr[i]*arr[i]));
                i++;
            }else {
                ans.push_back((arr[j]*arr[j]));
                j--;
            }
        }
        while(j>=0){
            ans.push_back((arr[j]*arr[j]));
            j--;
        }
        while(i<n){
            ans.push_back((arr[i]*arr[i]));
            i++;
        }
        return ans;

    }
};