class Solution
{
    public:
        long double apply(long double a, long double b, char op)
        {
            switch (op)
            {
                case '+':
                    return a + b;
                case '-':
                    return a - b;
                case '*':
                    return a * b;
                case '/':
                    if (fabs(b) < 1e-9) return 1e9;
                    return a / b;
            }
            return 0.0;
        }

    bool solve(vector < long double > &num, vector<char> &ops)
    {
        int n = num.size();
        if (n == 1)
        {
            if (fabs(num[0] - 24) < 1e-6) return true;
            return false;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;

                long double a = num[i], b = num[j];

                vector < long double > next;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j) next.push_back(num[k]);
                }

                for (char op: ops)
                {
                    long double temp = apply(a, b, op);
                    next.push_back(temp);

                    if (solve(next, ops)) return true;

                    next.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int> &nums)
    {
        vector<char> ops = { '+',
            '-',
            '*',
            '/' };
        vector < long double > num(nums.begin(), nums.end());
        return solve(num, ops);
    }
};