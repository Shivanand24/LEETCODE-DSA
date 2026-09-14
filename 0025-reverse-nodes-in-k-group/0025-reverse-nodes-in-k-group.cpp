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

void reverse(ListNode* left, int size) {
        ListNode* curr = left;
        ListNode* prev = NULL;

        while (size--) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {



         if (head == NULL)
            return head;

        ListNode* left = head;
        ListNode* right;
        int size = k;
        ListNode* res = NULL;
        ListNode* prevLeft = NULL;

        while (true) {

            right = left;

            for (int i = 0; i < size - 1; i++) {

                if (right == NULL)
                    break;

                right = right->next;
            }

            if (right) {

                ListNode* nextleft = right->next;

                reverse(left, size);

                if (prevLeft)
                    prevLeft->next = right;

                prevLeft = left;

                if (res == NULL)
                    res = right;

                left = nextleft;
            }

            else {

                if (prevLeft)
                    prevLeft->next = left;

                if (res == NULL)
                    res = left;

                break;
            }
        }

        return res;
    }
};