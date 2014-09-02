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
    ListNode *partition(ListNode *head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummy1(-1), dummy2(-1);
        ListNode *rear1(&dummy1), *rear2(&dummy2);
        while(head) {
            if(head->val < x) {
                rear1->next = head;
                rear1 = rear1->next;
            }
            else {
                rear2->next = head;
                rear2 = rear2->next;
            }
            head = head->next;
        }
        rear1->next = dummy2.next;
        rear2->next = nullptr;
        return dummy1.next;
    }
};
