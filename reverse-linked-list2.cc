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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1), *prev_m(nullptr), *prev(&dummy), *cur(head);
        dummy.next = head;
        for(int i=1; i<=n && cur; ++i) {
            if(i == m) prev_m = prev;
            if(i > m) {
                prev->next = cur->next;
                cur->next = prev_m->next;
                prev_m->next = cur;
                
                cur = prev->next;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
