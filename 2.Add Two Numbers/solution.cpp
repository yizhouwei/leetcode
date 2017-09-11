/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result = new ListNode((l1->val + l2->val) % 10);
        int overflow = (l1->val + l2->val) / 10;
        ListNode * tmp = result;
        while (l1->next && l2->next){
            l1 = l1->next;
            l2 = l2->next;
            tmp->next = new ListNode((l1->val + l2->val + overflow) % 10);
            tmp = tmp->next;
            overflow = (l1->val + l2->val + overflow) / 10;
        }
        if (l1->next) tmp->next = l1->next;
        if (l2->next) tmp->next = l2->next;
        while(overflow){
            if (!tmp->next){
                tmp->next = new ListNode(1);
                break;
            }
            tmp = tmp->next;
            int tmpint = tmp->val;
            tmp->val = (tmpint + overflow) % 10;
            overflow = (tmpint + overflow) / 10;
        }
        return result;
    }
};
