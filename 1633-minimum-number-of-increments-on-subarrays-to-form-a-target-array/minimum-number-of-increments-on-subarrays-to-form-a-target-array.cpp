class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        int c=a[0];
        for (int i=1;i<a.size();i++)
            c += max(a[i] - a[i - 1], 0);
        return c;
    }
};