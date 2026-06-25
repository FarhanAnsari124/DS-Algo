class Solution {
    public int totalFruit(int[] fruits) {
        int n=fruits.length;
        int i=0;
        int j=0;
        int len=0;
        int maxlen=0;
        HashMap<Integer,Integer> mapy = new HashMap<>();
        while(j<n){
            mapy.put(fruits[j],mapy.getOrDefault(fruits[j],0)+1);
            while(mapy.size()>2){
                mapy.put(fruits[i],mapy.get(fruits[i])-1);
                if(mapy.get(fruits[i])==0){
                    mapy.remove(fruits[i]);
                }
                i++;
            }
            len=j-i+1;
            maxlen=Math.max(len,maxlen);
            j++;
        }
        return maxlen;
    }
}