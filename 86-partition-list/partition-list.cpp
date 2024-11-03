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
    ListNode* partition(ListNode* head, int x) {

        if(!head || !head->next)    return head;
        // two lists 
        // list 1 containing nodes less than x
        // remaing nodes containing nodes greater than x

        ListNode* list1 = new ListNode();
        ListNode* list2 = new ListNode();
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(head != nullptr){
            if(head->val < x){
                temp1->next = head;
                temp1 = temp1->next;
            }else{
                temp2->next = head;
                temp2 = temp2->next;
            }

            head = head->next;
        }

        temp1->next = list2->next;
        temp2->next = nullptr;

        ListNode* newHead = list1->next;
        delete list1;
        delete list2;

        return newHead;
    }
};