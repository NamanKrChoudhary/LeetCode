/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> lvl;
        lvl.push(root);
        long long int maxx = LLONG_MIN;
        long long int maxind = 0;
        long long int cnt = 0;
        while(!lvl.empty())
        {
            cnt = cnt + 1;
            long long int len = lvl.size();
            long long int curr = 0;
            for(int i=0; i<len; i++)
            {
                TreeNode* currnode = lvl.front();
                lvl.pop();
                curr = curr + (currnode->val);
                if(currnode->left != NULL) lvl.push(currnode->left);
                if(currnode->right != NULL) lvl.push(currnode->right);
            }
            if(maxx < curr)
            {
                maxx = curr;
                maxind = cnt;
            }
        }
        return maxind;
    }
};