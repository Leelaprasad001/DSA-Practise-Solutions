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
class Solution {
    public ListNode reverse(ListNode root){
        ListNode temp = root, prev = null;
        while(temp != null){
            ListNode front = temp.next;
            temp.next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    public ListNode reverseBetween(ListNode head, int left, int right) {

        if (head == null || left == right) 
            return head;
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev.next;
        }
        
        ListNode start = prev.next;
        ListNode end = start;
        
        for (int i = 0; i < right - left; i++) {
            end = end.next;
        }

        ListNode next = end.next;
        
        end.next = null;
        prev.next = reverse(start);

        start.next = next;
        return dummy.next;
    }
}
