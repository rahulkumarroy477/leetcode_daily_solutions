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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> mp;
        
        for(const auto &x:nums)
            mp.insert(x);
        ListNode* curr = head;
        
        int count = 0;
        while(curr){
            
            // jab tak set me na mile
            while(curr and !mp.count(curr->val)){
                curr = curr->next;
            }
            //ek component mil gaya
            if(curr)    count++;
            
            // usse jude sabe ko skip karo
            while(curr and mp.count(curr->val)){
                curr = curr->next;
            }
        }
        
        return count;
    
        
    }
};