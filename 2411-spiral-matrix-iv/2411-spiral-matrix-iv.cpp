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
        vector<vector<int>>mat(m, vector<int>(n));
        ListNode* curr = head;
        vector<int>nums(m*n, -1);
        int i = 0;
        while(i < m*n && curr)
        {
            nums[i] = curr->val;
            curr = curr->next;
            i++;
        }
        int top = 0, left = 0;
        int ryt = n - 1, down = m - 1;

        int j = 0;
        int dir = 0;
        while(top <= down && left <= ryt)
        {
            if(dir == 0){
                for(int i=left; i<=ryt; i++)
                {
                    mat[top][i] = nums[j];
                    j++; 
                }
                top++;
            }
            else if(dir == 1){
                for(int i=top; i<=down; i++)
                {
                    mat[i][ryt] = nums[j];
                    j++;
                }
                ryt--;
            }
            else if(dir == 2){
                for(int i=ryt; i>=left; i--)
                {
                    mat[down][i] = nums[j];
                    j++;
                }
                down--;
            }
            else {
                for(int i=down; i>=top; i--)
                {
                    mat[i][left] = nums[j];
                    j++;
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return mat;
    }
};