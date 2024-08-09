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
    public ListNode Reverse(ListNode root){
        ListNode temp = root, prev = null;
        while(temp != null){
            ListNode front = temp.next;
            temp.next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    public ListNode removeNodes(ListNode head) {
        head = Reverse(head);
        ListNode temp = head;
        ListNode curr = temp.next;
        int max = temp.val;

        while(curr != null){
            if(curr.val >= max){
                max = curr.val;
                temp = curr;
            } else {
                temp.next = curr.next;
            }
            curr = curr.next;
        }

        return Reverse(head);
    }
}