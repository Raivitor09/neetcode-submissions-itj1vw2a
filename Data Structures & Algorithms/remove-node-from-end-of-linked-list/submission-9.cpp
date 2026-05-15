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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) return nullptr;
         
        head = reversed(head);
        if (n == 1) return head->next;

        ListNode* dummy = head;

        while (n - 2) {
            dummy = dummy->next;
            n--;
        }

        dummy->next = dummy->next->next;

        head = reversed(head);

        return head;
    }
    ListNode* reversed(ListNode* head) {
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
    int size(ListNode* head) {
        int res = 0;
        ListNode* dummy = head;

        while (head) {
            res++;
            dummy = dummy->next;
        }

        return res;
    }
};
