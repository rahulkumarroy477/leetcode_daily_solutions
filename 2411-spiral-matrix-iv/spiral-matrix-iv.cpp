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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        if(head == nullptr) return ans;
        ListNode* temp = head;

        int sr = 0, sc = 0, er = m-1, ec = n-1;
        while(temp!=nullptr){
            for(int i = sc;i<=ec and temp!=nullptr;i++){
                ans[sr][i] = temp->val;
                temp = temp->next;

            }
            sr++;

            for(int i = sr;i<=er and temp!=nullptr;i++){
                ans[i][ec] = temp->val;
                temp = temp->next;
            }
            ec--;
            for(int i = ec;i>=sc and temp!=nullptr;i--){
                ans[er][i] = temp->val;
                temp = temp->next;
            }
            er--;
            for(int i = er;i>=sr and temp!=nullptr;i--){
                ans[i][sc] = temp->val;
                temp = temp->next;
            }
            sc++;
        }

        return ans;
    }
};