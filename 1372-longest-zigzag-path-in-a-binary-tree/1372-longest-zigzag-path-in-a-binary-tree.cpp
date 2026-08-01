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
    void dfs(map<TreeNode*, pair<long long int, long long int>>& lr, TreeNode* curr)
    {
        if(curr->left != NULL) dfs(lr, curr->left);
        if(curr->left == NULL) lr[curr].first = 0;
        if(curr->right != NULL) dfs(lr, curr->right);
        if(curr->right == NULL) lr[curr].second = 0;
        long long int right = 0, left = 0;
        if(curr->left != NULL)
        {
            left = lr[curr->left].second + 1;
        }
        if(curr->right != NULL) right = lr[curr->right].first+1;
        lr[curr].first = left;
        lr[curr].second = right;
        return;

    }
    int longestZigZag(TreeNode* root) {
        //long long int n = 0;
        map<TreeNode*, pair<long long int, long long int>> lr;
        dfs(lr, root);
        long long int req = 0;
        for(auto i: lr)
        {
            req = max(req, i.second.first);
            req = max(req, i.second.second);
        }
        return req;
    }
};