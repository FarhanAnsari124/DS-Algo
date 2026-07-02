class Solution {
    public int[] nse(int[] arr){
        int n=arr.length;
        int[] nse = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            while(!st.isEmpty() && arr[st.peek()]>=curr){
                st.pop();
            }
            if(st.isEmpty()){
                nse[i]=n;
            }else{
                nse[i]=st.peek();
            }
            st.push(i);
        }
        return nse;
    }
    public int[] psee(int[] arr){
        int n=arr.length;
        int[] psee = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(!st.isEmpty() && arr[st.peek()]>curr){
                st.pop();
            }
            if(st.isEmpty()){
                psee[i]=-1;
            }else{
                psee[i]=st.peek();
            }
            st.push(i);
        }
        return psee;
    }
    public int sumSubarrayMins(int[] arr) {
        long total_sum=0;
        int n=arr.length;
        int mod = (int)1e9+7;
        int []nse = nse(arr);
        int []psee =psee(arr);
        for(int i=0;i<n;i++){
            int end_points = nse[i] - i;
            int start_points = i-psee[i];
            total_sum=(total_sum + ((long)end_points*start_points*arr[i])%mod)%mod;
        }
        return (int)(total_sum%mod);
    }
}