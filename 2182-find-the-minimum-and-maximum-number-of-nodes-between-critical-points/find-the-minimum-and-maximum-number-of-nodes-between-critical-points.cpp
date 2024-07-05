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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == nullptr) return {-1,-1};
        int count = 0;
        int minDistance = INT_MAX;
        int maxDistance = -1;

        ListNode* prev = head;
        ListNode* temp = head->next;
        int left = -1, curr = -1, right = -2;
        while(temp->next!=nullptr){
            if(temp->val > prev->val && temp->val > temp->next->val || 
                temp->val < prev->val && temp->val < temp->next->val)
            {
                if(left == -1)
                   curr = left = count; 
                else if(curr != -1){
                    minDistance = min(minDistance,count-curr);
                    curr = count;
                    right = count;
                }

            }
            count++;
            prev = temp;
            temp = temp->next;
        }
        maxDistance = right - left;
        if(left == -1 || left == curr)  return {-1,-1};
        return {minDistance,maxDistance};
    }
};