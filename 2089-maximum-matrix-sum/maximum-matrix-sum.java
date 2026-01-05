class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int min=Integer.MAX_VALUE;
        long sum=0;
        int m=matrix.length;
        int n=matrix[0].length;
        int negcnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    negcnt++;
                }
                int abs=Math.abs(matrix[i][j]);
                min=Math.min(min,abs);
                sum+=abs;
            }
        }
        if(negcnt%2==0){
            return sum;
        }
        return sum-2*min;
    }
}