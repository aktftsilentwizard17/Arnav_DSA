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
    ListNode* partition(ListNode* head, int x) {
        ListNode slist(0,nullptr);
        ListNode blist(0,nullptr);
        ListNode* small = &slist;
        ListNode* big = &blist;

        while(head!=nullptr){
            if(head->val<x){
                small->next=head; //attach to small list
                small=small->next;
            }
            else{
                big->next=head; //attach to big list
                big=big->next;
            }
            head=head->next;
        }

        small->next=blist.next; //head
        big->next=nullptr;
        return slist.next;
    }
};