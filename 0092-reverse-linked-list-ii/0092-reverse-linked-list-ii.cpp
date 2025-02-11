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
        ListNode* temp = head;
        int cnt = 1;
        
        while (cnt < left && temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        stack<int> st;
        ListNode* track = temp;
        int len = right - left + 1;
        
        while (len > 0 && temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
            len--;
        }
        
        while (!st.empty() && track != nullptr) {
            track->val = st.top();
            st.pop();
            track = track->next;
        }
        
        return head;
    }
};
