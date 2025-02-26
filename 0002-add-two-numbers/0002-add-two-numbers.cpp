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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* tail = temp;
        
        int carry = 0;

        while(l1 != nullptr || l2!=nullptr || carry){
            int dig1 = (l1 != nullptr) ? l1->val : 0;
            int dig2 = (l2 != nullptr) ? l2->val : 0;

            int sum = dig1 + dig2 + carry;
            int finalDig = sum%10;
            carry = sum/10;

            ListNode* temp1 = new ListNode(finalDig);
            tail->next = temp1;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        return temp->next;
    }
};