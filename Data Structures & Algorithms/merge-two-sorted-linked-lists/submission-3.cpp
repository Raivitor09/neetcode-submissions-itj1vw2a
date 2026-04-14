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
        ListNode dummy(0); // return in the end the whole list
        ListNode* merged = &dummy; // iterate through the list

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                merged->next = list1;
                list1 = list1->next;
            } else {
                merged->next = list2;
                list2 = list2->next;
            }
            merged = merged->next;
        }

        if (list1) { // if left nodes in the list1
            merged->next = list1;
        } else { // if left nodes in the list2
            merged->next = list2;
        }

        return dummy.next; // dummy is at the first position, so he will point to the whole linked list
    }
};
