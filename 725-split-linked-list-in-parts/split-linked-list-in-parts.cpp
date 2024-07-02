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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        vector<ListNode*> ans(k, nullptr);
        int n = 0; 
        while(temp!=nullptr){
            // cout<<temp->val<<" ";
            n++;
            temp = temp->next;
        }
        int partSize = n / k;
        int extra = n % k;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        for (int i = 0; i < k; ++i) {
            ans[i] = curr;
            int currentPartSize = partSize + (i < extra ? 1 : 0);
            
            for (int j = 0; j < currentPartSize; ++j) {
                prev = curr;
                if (curr != nullptr) {
                    curr = curr->next;
                }
            }
            
            if (prev != nullptr) {
                prev->next = nullptr;
            }
        }
        
        return ans;
        
    }
};