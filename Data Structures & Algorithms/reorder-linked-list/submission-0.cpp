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
    void reorderList(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;

        while (second != nullptr) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        ListNode* first = head;
        second = prev;

        while (second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next; 

            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }

    }
};
// 1->2->null    null<-3<-4
//                           sec
//                        prev
//                    temp

// 1 -> 2 -> null <- 3 <- 4
//      F   t1t2     S

// 1 -> 4 -> 2 -> 3 -> null

// divide in two halves
// reverse the second half
// merge the tow halves
