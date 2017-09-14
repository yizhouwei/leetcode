class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* tmp = new ListNode(0);
        ListNode* result = tmp;
        while (l1 && l2){
            if (l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            }
            else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        if (l2) tmp->next = l2;
        else tmp->next = l1;
        result = result->next;
        return result;
    }
};