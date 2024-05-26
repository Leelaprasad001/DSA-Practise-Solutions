/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        ListNode* tmp = NULL;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        
        int res = 0;
        while(slow != NULL){
            res = max(res, (prev->val + slow->val));
            prev = prev->next;
            slow = slow->next;
        }
        
        return res;
    }
};