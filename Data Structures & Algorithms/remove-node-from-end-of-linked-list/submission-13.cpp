class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        head = reverseList(head);

        if(n == 1){
            head = head->next;
            return reverseList(head);
        }

        ListNode* curr = head;

        for(int i = 1; i < n - 1; i++){
            curr = curr->next;
        }

        curr->next = curr->next->next;

        return reverseList(head);
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;

        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};