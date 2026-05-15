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
    int getSize (ListNode* head) {
        int res = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            res++;
            curr = curr->next;
        }

        return res;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* runner = head;
        int size = getSize(head);

        if (size == 1 || size == 0) {
            return nullptr;
        }

        if (size == n) {
            return head;
        }

        while (n - 1) {
            runner = runner->next;
            n--;
        }

        runner->next = runner->next->next;

        return head;
    }
};
