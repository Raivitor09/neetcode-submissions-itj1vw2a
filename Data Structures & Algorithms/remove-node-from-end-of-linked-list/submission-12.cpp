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
        int size = listSize(head);
        if(size == n) return head->next;

        head = reverseList(head);

        int count = 1;
        ListNode* dummy = head;

        if(n == 1) {
            head = head->next;

            head = reverseList(head);

            return head;
        }

        while(count < n - 1) {
            dummy = dummy->next;
            count++;
        }
        
        dummy->next = dummy->next->next;

        head = reverseList(head);

        return head;
    }

     ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* nextHead = head;

        while (head) {
            nextHead = head->next;
            head->next = prev;
            prev = head;
            head = nextHead;
        }

        return prev;
    }

    int listSize(ListNode* head) {
        int size = 0;

        while(head) {
            head= head->next;
            size++;
        }

        return size;
    }
};
