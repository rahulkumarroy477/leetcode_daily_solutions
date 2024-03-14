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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(l1!=nullptr and l2!=nullptr){
            if(l1->val<l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        if(l1!=nullptr){
            temp->next = l1;
        }
        else temp->next = l2;
        
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // merge two sorted list
        ListNode* temp = nullptr;
        for(ListNode* list : lists){
            temp = mergeTwoLists(temp,list);
        }
        return temp;
        
    }
};