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

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (head != nullptr) {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        ListNode* runner = head;
        int size = getSize(head);

        if (size == 1 || size == 0) {
            return nullptr;
        }

        while (n - 1) {
            runner = runner->next;
            n--;
        }
        head = reverse(head);
        if (runner == head) {
            return head->next;
        }

        ListNode* curr = head;
        while (curr-> next != runner) {
            curr = curr->next;
        }

        curr->next = runner->next;

        return head;
    }
};
