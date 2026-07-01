class Solution {
    public void reverseString(char[] s) {
        Stack<Character>st = new Stack<>();
        int n=s.length;
        for(int i=0;i<n;i++){
            st.push(s[i]);
        }
        String rev="";
        while(!st.isEmpty()){
            rev+=st.pop();
        }
        for(int i=0;i<n;i++){
            s[i]=rev.charAt(i);
        }
    }
}