class Solution {
    public int[] nge(int[] arr){
        int n=arr.length;
        int[] nge = new int[n];
        Stack<Integer>st = new Stack<>();
        for(int i=2*n-1;i>=0;i--){
            int ind=i%n;
            int curr=arr[ind];
            while(!st.empty() && arr[st.peek()]<=curr){
                st.pop();
            }
            if(i<n){
                if(st.isEmpty()){
                    nge[i]=-1;
                }else{
                    nge[i]=st.peek();
                }
            }
            st.push(ind);
        }
        return nge;
    }
    public int[] nextGreaterElements(int[] nums) {
        int n=nums.length;
        int []nge = nge(nums);
        for(int i=0;i<n;i++){
            if(nge[i]!=-1)
            nge[i]=nums[nge[i]];
        }
        return nge;
    }
}