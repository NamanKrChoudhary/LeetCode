struct trienode{
    string curr;
    bool off = false;
    map<string, trienode*> child;
    trienode(string s) {curr = s;}
};

void adder(trienode* root, vector<string>& path)
{
    trienode* curr = root;
    for(int i=0; i<path.size(); i++)
    {
        if(curr->child.count(path[i])) curr = curr->child[path[i]];
        else
        {
            curr->child[path[i]] = new trienode(path[i]);
            curr = curr->child[path[i]];
        }
    }
}

string checker(map<string, trienode*>& prev, trienode* node)
{
    string just = "";
    for(auto i: node->child)
    {
        string temp = checker(prev, i.second);
        just = just+temp;
    }
    if(prev.count(just)) 
    {
        node->off = true;
        prev[just]->off = true;
    }
    else if(just != "") prev[just] = node;
    just = "[" + node->curr + just + "]";
    return just;
}

void filler(vector<vector<string>>& fill, vector<string>& vis, trienode* node)
{
    if(node->off) return;
    vis.push_back(node->curr);
    fill.push_back(vis);
    for(auto i: node->child)
    {
        filler(fill, vis, i.second);
    }
    vis.pop_back();
    return;
}

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        trienode* root = new trienode("/");
        for(auto i: paths) adder(root, i);
        map<string, trienode*> vis;
        vector<vector<string>> full;
        string end = checker(vis, root);
        vector<string> visi;
        for(auto i: root->child)
        {
            filler(full, visi, i.second);
        }
        return full;
    }
};