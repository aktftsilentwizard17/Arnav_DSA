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
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i=0;i<n;i++){
            fast=fast->next;
        }

        if(fast==NULL){
            ListNode* todelete = head;
            head=head->next;
            delete todelete;
            return head;
        }

        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }

        //keep a distance of n between slow and fast pointer, when fast reaches end, target is just front of slow
        ListNode* todelete = slow->next;
        slow->next = slow->next->next;
        delete todelete;

        return head;
    }
};