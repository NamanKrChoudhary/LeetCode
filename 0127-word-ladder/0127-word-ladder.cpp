class Solution {
public:

    bool checker(string a, string b)
    {
        if(a.size() != b.size()) return false;
        int cnt = 0;
        for(int i=0; i<a.size(); i++) if(a[i] != b[i]) cnt = cnt + 1;
        if(cnt == 1) return true;
        else return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>> adj(n);
        int end = -1;
        int beg = -1;
        for(int i=0; i<n; i++)
        {
            if(wordList[i] == endWord) {end = i;}
            if(wordList[i] == beginWord) {beg = i;}
        } 
        if(end == -1) return 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int cnt = 0;
                if(wordList[i].size() != wordList[j].size()) continue;
                for(int k=0; k<wordList[i].size(); k++)
                {
                    if(wordList[i][k] != wordList[j][k]) cnt = cnt + 1;
                }
                if(cnt == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int l = 0;
        if(beg == -1) l = 1;
        queue<int> q;
        vector<bool> vis(n);
        q.push(end); vis[end] = true;
        int ans = 0;
        while(!q.empty())
        {
            l++;
            int len = q.size();
            for(int i=0; i<len; i++)
            {
                int curri = q.front();
                q.pop();
                if(checker(beginWord, wordList[curri])) {ans = l; break;}
                for(int j=0; j<adj[curri].size(); j++)
                {
                    if(!vis[adj[curri][j]]) {vis[adj[curri][j]] = true; q.push(adj[curri][j]);}
                }
            }
        }
        return ans;
    }
};