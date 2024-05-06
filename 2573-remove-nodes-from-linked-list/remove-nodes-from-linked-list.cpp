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

/*
To reverse the list
Approach1: Stack-->creating new Linked list
Approach2: Recursion
Approach3: Reverse the list
*/
class Solution {
public:
    
    ListNode* removeNodes(ListNode* head) {
        // right to left traversal
//         stack<ListNode*> st;
//         ListNode* curr = head;
        
//         while(curr!=NULL){
//             st.push(curr);
//             curr = curr->next;
//         }
        
//         curr = st.top();
//         st.pop();
        
//         int maxVal = curr->val;
//         ListNode* newHead = new ListNode(curr->val);
//         while(!st.empty()){
//             curr = st.top();
//             st.pop();
//             if(curr->val<maxVal){
//                 continue;
//             }
            
//             ListNode* newNode = new ListNode(curr->val);
//             newNode->next = newHead;
//             newHead = newNode;
//             maxVal = curr->val;
            
//         }
//         return newHead;
        
        // Approach 2
        if(head==NULL || head->next == NULL)    return head;
        
        ListNode* newNode = removeNodes(head->next);
        
        if(head->val < newNode->val){
            delete head;
            return newNode;
        }
        
        head->next = newNode;
        return head;
    }
};