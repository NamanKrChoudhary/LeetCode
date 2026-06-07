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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> parent, child;
        for(int i=0; i<descriptions.size(); i++)
        {
            parent.insert(descriptions[i][0]);
            child.insert(descriptions[i][1]);
        }
        int root = -1;
        for(auto i: parent) if(child.find(i) == child.end()) {root = i; break;}
        for(auto i: parent) child.insert(i);
        map<int, TreeNode*> mp;
        for(auto i: child) {mp[i] = new TreeNode(); mp[i] -> val = i;}
        for(int i=0; i<descriptions.size(); i++)
        {
            if(descriptions[i][2] == 1) mp[descriptions[i][0]] -> left = mp[descriptions[i][1]];
            else mp[descriptions[i][0]] -> right = mp[descriptions[i][1]];
        }
        //for(auto i: mp) cout << i.first << " "; cout << endl;
        return mp[root];
    }
};