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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;

        vector<int> values;

        //for 1..3..5..7 etc

        if(temp == NULL || temp->next == NULL)return head;

        while(temp!=NULL && temp->next != NULL){
            values.push_back(temp->val);
            temp = temp->next->next;
        }

        if(temp){
            values.push_back(temp->val);
        }

        temp = head->next;

        //for 2..4..6..8 etc

        while(temp!=NULL && temp->next != NULL){
            values.push_back(temp->val);
            temp = temp->next->next;
        }

        if(temp){
            values.push_back(temp->val);
        }

        for
        (int i=0; i<values.size(); i++){
            cout<<values[i]<<" ";
        }

        int idx = 0;

        temp = head;

        while(temp!=NULL){
            temp->val = values[idx++];
            temp = temp->next;
        }

        return head;
    }
};