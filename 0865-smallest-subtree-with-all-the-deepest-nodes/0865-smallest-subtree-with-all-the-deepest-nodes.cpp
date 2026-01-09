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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        map<TreeNode* , long long int> nodelvl;
        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        long long int cnt = 0;
        set<TreeNode*> lowest;
        while(!q.empty())
        {
            cnt = cnt + 1;
            long long int len = q.size();
            set<TreeNode*> temp;
            for(int i=0; i<len; i++)
            {
                TreeNode* currnode = q.front();
                temp.insert(q.front());
                q.pop();
                nodelvl[currnode] = cnt;
                if(currnode->left != NULL) 
                {
                    q.push(currnode->left);
                    parent[currnode->left] = currnode;
                }
                if(currnode->right != NULL) 
                {
                    q.push(currnode->right);
                    parent[currnode->right] = currnode;
                }
            }
            if(q.empty()) lowest = temp;
        }
        //cout << lowest.size() << endl;
        while(lowest.size() > 1)
        {
            set<TreeNode*> next;
            for(auto i: lowest)
            {
                next.insert(parent[i]);
                //cout << i->val << " " << parent[i]->val << endl;
            }
            lowest = next;
        }
        return *lowest.begin();
    }
};