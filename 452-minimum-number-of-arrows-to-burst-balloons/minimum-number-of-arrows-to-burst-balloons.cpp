class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    });
       int i=0;
       int j=1;
       int n=points.size();
       int cnt=0;
       while(i<n){
        while(j<n && points[i][1]>=points[j][0]){
            j++;
        }
        i=j;
        j++;
        cnt++;
       }

       return cnt;
    }
};