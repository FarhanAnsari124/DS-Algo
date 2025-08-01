class Solution {
public:
    vector<vector<int>> generate(int numrows) {
        if(numrows==1)return {{1}};
        else{
            vector<vector<int>>main;
            main.push_back({1});
            for(int i=1;i<numrows;i++){
                vector<int>temp;
                temp.push_back(1);
                for(int j=0;j<i-1;j++){
                    temp.push_back(main[i-1][j]+main[i-1][j+1]);
                }
                temp.push_back(1);
                main.push_back(temp);
            }
            return main;

        }

    }
};