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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            next=curr->next;//store next node in next
            curr->next=prev;//reverse the next link
            prev=curr;//move prev ahead
            curr=next;//move curr ahead
        }

        return prev;//if it was a void type fnx [void(**head)], we would do *head=prev
    }
};