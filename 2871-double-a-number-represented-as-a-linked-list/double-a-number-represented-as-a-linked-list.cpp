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
    ListNode* solve(ListNode* head){
        if(head->next==NULL){
            head->val = head->val*2;
            return head;
        }
        
        ListNode* number = solve(head->next);
        head->val = head->val*2 + number->val/10;
        number->val = number->val%10;
        
        
        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead = solve(head);
        
        if(newHead->val>9){
            ListNode* newNode = new ListNode(1,newHead);
            newHead->val = newHead->val%10;
            newHead = newNode;
        }
        
        return newHead;
    }
};