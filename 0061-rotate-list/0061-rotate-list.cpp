class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL) {
            return head;
        }

        ListNode* fast = head;
        int n = 1;

        // Find last node and length
        while (fast->next != NULL) {
            n++;
            fast = fast->next;
        }

        k = k % n;

        if (k == 0) {
            return head;
        }

        ListNode* t = head;
        int count = 1;

        // Find node at position n-k
        while (t != NULL) {

            if (count == n - k) {
                break;
            }

            count++;
            t = t->next;
        }

        // Save new head
        ListNode* res = t->next;

        // Connect last node to old head
        fast->next = head;

        // Break the list
        t->next = NULL;

        return res;
    }
};