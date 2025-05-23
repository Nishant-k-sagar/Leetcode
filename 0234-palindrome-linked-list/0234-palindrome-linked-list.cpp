class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* pre = NULL;

        while(head != NULL){
        ListNode* next = NULL;
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre; 
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next); 
        slow = slow->next;

        while(slow != NULL){
            if(head->val != slow->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
