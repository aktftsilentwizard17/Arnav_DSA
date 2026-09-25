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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        stack<int> st;

        ListNode* curr = head;
        while (curr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        vector<int> res(arr.size(), 0);

        int i = arr.size() - 1;
        while (i >= 0) {
            // Remove values that cannot be next greater elements
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // Stack top is the next greater value
            if (!st.empty()) {
                res[i] = st.top();
            }

            st.push(arr[i]);
            i--;
        }

        return res;
    }
};