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
    const long long int mod = 1e9+7;
    long long int dfs(map<TreeNode*, long long int>& mp, TreeNode* node)
    {
        long long int req = node->val;
        if(node->left != NULL) req = req + dfs(mp, node->left);
        if(node->right!= NULL) req = req + dfs(mp, node->right);
        mp[node] = req;
        return req;
    }
    int maxProduct(TreeNode* root) {
        map<TreeNode*, long long int> mp;
        mp[root] = dfs(mp, root);
        long long int maxx = 0;
        long long int total = mp[root];
        for(auto i: mp)
        {
            long long int a = i.second;
            long long int b = total-i.second;
            long long int curr = a*b;
            maxx = max(maxx, curr);
        }
        return maxx%mod;
    }
};