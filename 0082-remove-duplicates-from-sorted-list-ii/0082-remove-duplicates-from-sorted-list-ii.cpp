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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head != nullptr) {
            // Check if head is the start of a duplicate sequence
            if (head->next != nullptr && head->val == head->next->val) {
                // Move head to the last node of the duplicate sequence
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Link prev past all duplicate nodes
                prev->next = head->next;
            } else {
                // No duplicate found, move prev forward
                prev = prev->next;
            }
            // Move head to the next node to process
            head = head->next;
        }

        return dummy.next;
    }
};