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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp1=list1,*temp2=NULL,*del=NULL;
        for(int i=1;i<a;i++) temp1=temp1->next;
        del = temp1->next;
        temp1->next=list2;
        for(int i = a;i<=b;i++) 
        {
            temp2=del->next;
            delete(del);
            del=temp2;
        }
        while(list2->next!=NULL) list2=list2->next;
        list2->next=temp2;
        return list1;
        
    }
};