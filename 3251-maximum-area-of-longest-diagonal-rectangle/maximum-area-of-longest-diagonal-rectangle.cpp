class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        unordered_map<double,double>mapy;
        int n=d.size();
        double ans=0;
        for(int i=0;i<n;i++){
            int a=d[i][0];
            int b=d[i][1];
            double dia=sqrt((a*a)+(b*b));
            double area=a*b;
            if(mapy.find(dia)!=mapy.end() && mapy[dia]<area){
                mapy[dia]=area;
            }
            else if(mapy.find(dia)==mapy.end()) mapy[dia]=area;
            ans=(dia>ans)?dia:ans;
            for(auto x:mapy){
                cout<<x.first;
            }
        }
        cout<<endl<<ans;
        return mapy[ans];
    }
};