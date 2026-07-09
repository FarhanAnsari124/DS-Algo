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
class Pair{
    int first;
    ListNode second;
    Pair(int first,ListNode second){
        this.first=first;
        this.second=second;
    }
}
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Pair> minHeap = new PriorityQueue<>((a,b)-> Integer.compare(a.first,b.first));
        int n=lists.length;
        for(int i=0;i<n;i++){
            if(lists[i]!=null){
                minHeap.add(new Pair(lists[i].val,lists[i]));
            }
        }
        ListNode dummy = new ListNode(-1);
        ListNode temp = dummy;
        while(!minHeap.isEmpty()){
            Pair p=minHeap.poll();
            int node_val = p.first;
            ListNode node = p.second;
            temp.next = node;
            temp=temp.next;
            if(node.next!=null){
                minHeap.add(new Pair(node.next.val,node.next));
            }
        }
        return dummy.next;
    }
}