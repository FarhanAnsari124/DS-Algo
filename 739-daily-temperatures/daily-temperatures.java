class Solution {
    public int[] nextGreaterElement(int[] arr){
        int n=arr.length;
        int[] nge = new int[n];
        Stack<Integer>st = new Stack<>();
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(!st.isEmpty() && arr[st.peek()]<=curr){
                st.pop();
            }
            if(st.isEmpty()){
                nge[i]=-1;
            }else{
                nge[i]=st.peek();
            }
            st.push(i);
        }
        return nge;
    }
    public int[] dailyTemperatures(int[] temperatures) {
        int n=temperatures.length;
        int nge[] = nextGreaterElement(temperatures);
        for(int i=0;i<n;i++){
            if(nge[i]==-1){
                nge[i]=0;
            }
            else nge[i]=nge[i]-i;
        }
        return nge;
    }
}