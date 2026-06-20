class Solution {
    public void setZeroes(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        int [][] copy = new int[n][m];
        for(int i=0;i<n;i++){ //Copying my original matrix into copy matrix
            for(int j=0;j<m;j++){
                copy[i][j] = matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){//Traversing on copy array
            for(int j=0;j<m;j++){
                if(copy[i][j]==0){//cheching if an element is zero
                    for(int k=0;k<n;k++){//making the 'J' coloumn as zero
                        matrix[k][j]=0;
                    }
                    for(int k=0;k<m;k++){//making the 'I' row as zero
                        matrix[i][k]=0;
                    }
                }
            }
        }
    }
}