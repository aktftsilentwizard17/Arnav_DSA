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
    ListNode* swapPairs(ListNode* head) {
        // base case
        if(head==nullptr||head->next==nullptr){
            return head;
        }

        // choices
        ListNode* firstnode=head;
        ListNode* secondnode=head->next;

        // recursive call, common method for linked lists problems is to call rest of the list first
        ListNode* restoflist = swapPairs(secondnode->next);

        //backtrack/unwind stack
        firstnode->next=restoflist;
        secondnode->next=firstnode;

        return secondnode;
    }
};