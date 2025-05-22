class Solution {
public:
    bool checker(string a, string b)
    {
        long long int cnt = 0;
        if(a.size() != b.size()) return false;
        for(int i=0; i<a.size(); i++) if(a[i] != b[i]) cnt = cnt + 1;
        if(cnt == 1) return true;
        return false;
    }
    void dfs(vector<vector<string>>& lvl, vector<string>& temp, int curr, vector<vector<string>>& ans)
    {
        if(curr == -1) {ans.push_back(temp);return;}
        for(int i=0; i<lvl[curr].size(); i++)
        {
            if(checker(temp[temp.size()-1], lvl[curr][i])) 
            {
                temp.push_back(lvl[curr][i]);
                dfs(lvl, temp, curr-1, ans);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        bool check = true;
        vector<vector<string>> ans;
        vector<vector<string>>fin;
        for(int i=0; i<wordList.size(); i++) if(wordList[i] == endWord) {check = false; break;}
        if(check) return fin;
        map<string, vector<string>> mp;
        for(int i=0; i<wordList.size(); i++)
        {
            for(int j=i+1; j<wordList.size(); j++)
            {
                if(checker(wordList[i], wordList[j]))
                {
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                } 
            }
        }
        if(mp.find(beginWord) == mp.end())for(int i=0; i<wordList.size(); i++) if(checker(beginWord, wordList[i])) { mp[beginWord].push_back(wordList[i]);}
        map<string, bool> vis;
        for(int i=0; i<wordList.size(); i++) vis[wordList[i]] = false;
        queue<string> q;
        q.push({beginWord}); vis[beginWord] = true;
        map<string, int> ser;
        ser[beginWord] = 0; long long int cnt = 0;
        while(!q.empty())
        {
            long long int len = q.size();
            cnt = cnt+1;
            bool check = false;
            for(int i=0; i<len; i++)
            {
                string temp = q.front();
                q.pop();
                if(temp == endWord) {check = true; break;}
                for(auto i: mp[temp]) if(!vis[i]) {vis[i] = true; q.push(i); ser[i]=cnt;}
            }
            if(check) break;
        }
        vector<vector<string>> lvl(cnt);
        for(auto i: ser) 
        {
            if(i.second < cnt) lvl[i.second].push_back(i.first);
        }
        if(ser.find(endWord) == ser.end()) return ans;
        // vector<string> vec = {endWord};
        // lvl[lvl.size()-1] = vec;
        //for(int i=0; i<lvl.size(); i++) {for(int j=0; j<lvl[i].size(); j++) cout << lvl[i][j] << " "; cout << endl;}
        vector<string> temp; temp.push_back(endWord);
        dfs(lvl, temp, ser[endWord]-1, ans);
        for(int i=0; i<ans.size(); i++) reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
};