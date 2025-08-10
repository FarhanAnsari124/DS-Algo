class Solution {
public:
    int lcs(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        cout << n2;
        vector <int> prev(n2+1, 0),curr(n2+1,0);
        for (int i1 = 1; i1 <= n1; i1++)
        {
            for (int i2 = 1; i2 <= n2; i2++)
            {
                if (s1[i1-1] == s2[i2-1])
                {
                    curr[i2] = 1 + prev[i2 - 1];
                }
                else curr[i2] = max(prev[i2], curr[i2 - 1]);
                
            }
            prev=curr;
        }
        return curr[n2];
    }
    int minDistance(string word1, string word2) {
        int lcsub=lcs(word1,word2);
        return (word1.size()-lcsub)+(word2.size()-lcsub);
        
    }
};