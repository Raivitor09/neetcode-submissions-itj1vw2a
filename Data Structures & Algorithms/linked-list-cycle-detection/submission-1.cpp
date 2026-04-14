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
    bool hasCycle(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* fastPointer = head->next;
        ListNode* slowPointer = head;

        while (fastPointer != nullptr) {
            if (fastPointer == slowPointer) {
                return true;
            }

            slowPointer = slowPointer->next;

            if(fastPointer->next != nullptr) {
                fastPointer = fastPointer->next->next;
            } else {
                return false;
            }
        }
    }
};
