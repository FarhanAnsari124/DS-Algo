class Solution {
    public void setZeroes(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        int [] rows = new int[n];
        int [] cols = new int[m];
        for(int i=0;i<n;i++){//maintaing two 1D-arrays,marking it as 1 if im getting a zero at i,j;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){//making the whole row as zero if im getting 1 in rows[i];
            if(rows[i]==1){
                for(int k=0;k<m;k++){
                    matrix[i][k]=0;
                }
            }
        }
        for(int j=0;j<m;j++){//making the whole coloumn zero if im getting 1 in cols[j];
            if(cols[j]==1){
                for(int k=0;k<n;k++){
                    matrix[k][j]=0;
                }
            }
        }
    }
}