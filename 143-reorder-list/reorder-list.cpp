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
        if(!head || !head->next)    return head;

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    void reorderList(ListNode* head) {
        // get the middle node;
        ListNode* midNode = middleNode(head);
        ListNode* firstHalf = head;
        ListNode* secondHalf = reverseList(midNode->next);
        midNode->next = nullptr;

        // we have two list, now we will merge them
        while(secondHalf){
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};