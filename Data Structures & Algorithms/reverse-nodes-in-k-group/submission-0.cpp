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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroup = dummy;

        while (true) {
            // 1. Verificar se existem k nós
            ListNode* node = prevGroup;
            for (int i = 0; i < k; i++) {
                node = node->next;
                if (!node) return dummy->next;
            }

            // 2. Aplicar head insertion no grupo
            ListNode* curr = prevGroup->next;

            for (int i = 0; i < k - 1; i++) {
                ListNode* next = curr->next;

                curr->next = next->next;
                next->next = prevGroup->next;
                prevGroup->next = next;
            }

            // 3. Avançar para o próximo grupo
            prevGroup = curr;
        }
    }
};
