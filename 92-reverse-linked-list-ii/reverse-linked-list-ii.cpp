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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;

        for(int i = 1;i<left;i++){
            prev = prev->next;
        }

        ListNode* startNode = prev->next;
        ListNode* endNode = startNode;
        for(int i = left;i<right;i++){
            endNode = endNode->next;
        }

        ListNode* lastNode = endNode->next;
        endNode->next = nullptr;

        prev->next = reverseList(startNode);
        startNode->next = lastNode;

        return dummy->next;
    }
};