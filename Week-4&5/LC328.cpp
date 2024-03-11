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

// LeetCode 328. Odd Even Linked List 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* origin = head;
        ListNode* oddlist = head; 
        ListNode* evenlist = head->next; 
        ListNode* secondhead = evenlist; 

        while(oddlist != nullptr && evenlist != nullptr){
            oddlist->next = oddlist->next->next;
            evenlist->next = evenlist->next->next;
            oddlist = oddlist->next;
            evenlist = evenlist->next;
        }
        oddlist->next = secondhead;

        return origin;
    }
};
