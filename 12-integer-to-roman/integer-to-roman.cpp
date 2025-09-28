class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>>valueSymbol{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}
        };
        string res;
        for(int i=0;i<valueSymbol.size();i++){
            if(valueSymbol[i].first<=num){
                if(num==0)break;
                int time=num/valueSymbol[i].first;
                while(time--)res+=valueSymbol[i].second;
                num%=valueSymbol[i].first;
            }
        }
        return res;
    }
};