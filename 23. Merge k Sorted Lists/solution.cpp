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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return NULL;
        while (k > 1){
     //       cout<<k<<endl;
            int j = 0;
            int i;
            for (i = 0; i < k - 1 ; i = i + 2){
                lists[j] = mergeTwoLists(lists[i],lists[i+1]);
                j++;
            }
       //     cout<<i<<" "<<k<<endl;
            if (i < k) {
                lists[j] = lists[k - 1];
                j++;
            }
            k = j;
        }
        return lists[0];
    }
    
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