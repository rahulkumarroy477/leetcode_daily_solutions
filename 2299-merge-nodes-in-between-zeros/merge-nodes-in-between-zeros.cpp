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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* ansHead = new ListNode(0);
        ListNode* ansTemp = ansHead;
        int sum = 0;
        while(temp!=nullptr){
            if(temp->val == 0 && sum!=0){
                ansTemp->next = new ListNode(sum);
                ansTemp = ansTemp->next;
                sum = 0;
            }

            sum += temp->val;

            temp = temp->next;
        }

        return ansHead->next;
    }
};