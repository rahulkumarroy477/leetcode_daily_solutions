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
    ListNode* reverseList(ListNode* head) {

        // iterative

        // if(head==nullptr or head->next==nullptr)  return head;
        // ListNode* temp = nullptr;
        // ListNode* nex  = head->next;

        // while(nex!=nullptr)
        // {
        //     head->next = temp;
        //     temp = head;
        //     head = nex;
        //     nex = nex->next;
        // }

        // head->next = temp;
        // return head;

        // recursive

        if(head==NULL or head->next==NULL) return head;

        ListNode* rev = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;
        return rev;
    }
};