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
    int getListLength(ListNode* head){
        if(head == nullptr) return 0;
        return 1 + getListLength(head->next);
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        // get the length of linked list
        int len = getListLength(head);

        // divide the len in k parts
        int n = len/k;
        int rem_size = len%k;
        vector<ListNode*> ans(k,nullptr);
        ListNode* temp = head, *prev = nullptr;
        for(int i = 0;i<k;i++){
            ans[i] = temp;

            int currPartSize = n + (rem_size > 0?1:0);
            rem_size--;
            for(int j = 0;j<currPartSize;j++){
                prev = temp;
                if(temp!=nullptr){
                    temp = temp->next;
                }
            }
            
            if(prev != nullptr){
                prev->next = nullptr;
            }

        }

        return ans;
    }
};