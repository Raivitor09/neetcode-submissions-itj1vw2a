class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int sizeA = listSize(headA);
        int sizeB = listSize(headB);

        while (sizeA > sizeB) {
            headA = headA->next;
            sizeA--;
        }

        while (sizeB > sizeA) {
            headB = headB->next;
            sizeB--;
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }

    int listSize(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }
};