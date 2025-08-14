string operator*(const string &s, int times) {
    string result;
    result.reserve(s.size() * times);
    for (int i = 0; i < times; i++) {
        result += s;
    }
    return result;
}

string operator*(int times, const string &s) {
    return s * times;
}

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char ans = -1;
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            if (cnt == 2) ans = max(ans, num[i - 1]);
            if (num[i - 1] == num[i]) {
                cnt++;
            } else {
                cnt = 0;
            }
        }

        if (cnt == 2) ans = max(ans, num[n - 1]);
        if (ans == -1) return "";

        string t(1, ans);
        return t * 3; 
    }
};
