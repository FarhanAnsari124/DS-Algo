/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public int getLen(ListNode head){
        ListNode temp = head;
        int cnt=0;
        while(temp!=null){
            temp=temp.next;
            cnt++;
        }
        return cnt;
    }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int l1=getLen(headA);
        int l2=getLen(headB);
        ListNode t1 = headA;
        ListNode t2 = headB;
        if(l1<l2){
            int diff = l2-l1;
            while(diff>0){
                t2=t2.next;
                diff--;
            }
        }else{
            int diff = l1-l2;
            while(diff>0){
                t1=t1.next;
                diff--;
            }
        }
        while(t1!=null && t2!=null){
            if(t1==t2){
                return t1;
            }
            t1=t1.next;
            t2=t2.next;
        }
        return null;
    }
}