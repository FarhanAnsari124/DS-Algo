class Pair{
    int first;
    int second;
    Pair(int first,int second){
        this.first=first;
        this.second=second;
    }
}
class Solution {
    public String[] findRelativeRanks(int[] score) {
        PriorityQueue<Pair> maxHeap = new PriorityQueue<>((a,b)-> Integer.compare(b.first,a.first));
        int n=score.length;
        for(int i=0;i<n;i++){
            maxHeap.add(new Pair(score[i],i));
        }
        String[] result = new String[n];
        int pos=1;
        while(!maxHeap.isEmpty()){
            Pair p = maxHeap.poll();
            if(pos==1){
                result[p.second]="Gold Medal";
            }else if(pos==2){
                result[p.second]="Silver Medal";
            }
            else if(pos==3){
                result[p.second]="Bronze Medal";
            }else{
                result[p.second]=String.valueOf(pos);
            }
            pos++;
        }
        return result;
    }
}