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

    ListNode* reverseList(ListNode* head){
        if(!head or !head->next)    return head;
        ListNode* rev = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return rev;
    }
    bool isPalindrome(ListNode* head) {
        // base case
        if(!head or !head->next)    return head;
        // go to middle
        ListNode* slow =head, *fast = head->next;
        
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // reversing the second half
        ListNode* newHead = reverseList(slow->next);
        slow = head, fast = newHead;
        while(fast!=NULL){
            if(slow->val!=fast->val){
                reverseList(newHead);
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        reverseList(newHead);
        return true;
    }
};