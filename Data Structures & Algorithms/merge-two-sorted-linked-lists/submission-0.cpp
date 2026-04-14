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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;

        ListNode* merged;

        if (head1 == nullptr) {
            return head2;
        } 
        
        if (head2 == nullptr) {
            return head1;
        }

        if (head1->val <= head2->val) {
            merged = head1;
            head1 = head1->next;
        } else {
            merged= head2;
            head2 = head2->next;
        }
        ListNode* fixedHead = merged;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                merged->next = head1;
                head1 = head1->next;
            } else {
                merged->next = head2;
                head2 = head2->next;
            }
            merged = merged->next;
        }

        if (head1 != nullptr) {
            merged->next = head1;
        } else {
            merged->next = head2;
        }

        return fixedHead;
    }
};
