class Solution {
public:
    string makeFancyString(string s) {
        vector<bool> vis(s.size(),0);
        for(int i=2; i<s.size(); i++)
        {
            if(s[i]==s[i-1] && s[i-1] == s[i-2]) vis[i-2] = true;
        }
        string curr = "";
        for(int i=0; i<s.size(); i++) if(!vis[i]) curr.push_back(s[i]);
        return curr;
    }
};