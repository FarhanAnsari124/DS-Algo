class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int tot=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());
        int cap=0;
        int i=0;
        while(cap<tot){
            cap+=capacity[i];
            i++;
        }
        return i;
    }
};