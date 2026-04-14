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
        int size = getSize(head);
        if (size == 0 || size == 1) return nullptr;
         
        head = reversed(head);
        
        ListNode* dummy = head;

        while (n - 1) {
            dummy = dummy->next;
            n--;
        }

        head = reversed(head);

        if (dummy == head) {
            return dummy->next;
        }

        ListNode* curr = head; // curr will delete the dummy node(node to be deleted)
        while (curr->next != dummy) {
            curr = curr->next;
        }

        curr->next = curr->next->next;

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
    int getSize(ListNode* head) {
        int res = 0;

        while (head) {
            res++;
            head = head->next;
        }

        return res;
    }
};
