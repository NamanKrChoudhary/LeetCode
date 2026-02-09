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
    TreeNode* filler(vector<long long int>& arr, long long int i, long long int j)
    {
        //cout << i << " " << j << endl;
        if(i == j)
        {
            TreeNode* curr = new TreeNode(arr[i]);
            curr->right = NULL;
            curr->left = NULL;
            return curr;
        }
        long long int sz = j-i+1;
        long long int currind = i+(sz/2);
        TreeNode* curr = new TreeNode(arr[currind]);
        curr->left = filler(arr, i, currind-1);
        if(currind+1 <= j) curr->right = filler(arr, currind+1, j);
        else curr->right = NULL;
        return curr;
    }
    void in(TreeNode* root, vector<long long int>& arr)
    {
        if(root == NULL) return;
        in(root->left, arr);
        arr.push_back(root->val);
        in(root->right, arr);
        return;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<long long int> arr;
        in(root, arr);
        return filler(arr, 0, arr.size()-1);
    }
};