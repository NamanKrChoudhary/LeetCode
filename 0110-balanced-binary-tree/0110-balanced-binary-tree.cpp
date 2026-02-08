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
    int checkh(TreeNode* root)
    {
        int l = 0,r=0;
        if(root->left == NULL) l = 0;
        else l = checkh(root->left);
        if(root->right == NULL) r = 0;
        else r = checkh(root->right);
        if(abs(r-l) > 1||(r==-1 || l==-1)) return -1;
        else return (1+max(r,l));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int ans = checkh(root);
        if(ans == -1) return false;
        else return true;
    }
};