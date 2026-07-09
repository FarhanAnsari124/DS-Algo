/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Pair {
    int first;
    ListNode second;

    Pair(int first, ListNode second) {
        this.first = first;
        this.second = second;
    }
}
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b)->Integer.compare(a.first,b.first));
        for(ListNode x: lists){
            if(x!=null){
                pq.add(new Pair(x.val,x));
            }
        }
        ListNode temp=new ListNode(-1);
        ListNode t=temp;
        while(!pq.isEmpty()){
            Pair x =pq.poll();
            temp.next=x.second;
            temp=temp.next;
            if(x.second.next!=null){
                pq.add(new Pair(x.second.next.val,x.second.next));
            }
        }
        return t.next;
        
    }
}