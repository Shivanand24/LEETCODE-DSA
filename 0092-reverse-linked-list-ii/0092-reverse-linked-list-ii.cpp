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
    ListNode* reverseBetween(ListNode* head, int left, int right) {


            ListNode * before = NULL;
            ListNode * t = head;
            if (head == NULL || left == right) return head;

            int pos = 1;
            while (pos < left) 
                  {
                    before = t ;
                    t = t -> next;
                    pos++;
                    continue;
                }

                ListNode*prev = NULL;

                ListNode*curr = t;
                int num = right - left +1;

                while (num>0){
                    ListNode*next = curr -> next;
                    curr -> next = prev;
                   
                    prev = curr;
                     curr = next ;

                    num--;
                }

                t -> next = curr;

                if (before != NULL){
                    before -> next =  prev;
                        return head;
                }
                return prev;
            
    

    }
};