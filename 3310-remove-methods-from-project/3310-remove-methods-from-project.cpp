class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<long long int>> out(n), in(n);
        for(int i=0; i<invocations.size(); i++)
        {
            out[invocations[i][0]].push_back(invocations[i][1]);
            in[invocations[i][1]].push_back(invocations[i][0]);
        }
        vector<bool> sus(n, false);
        queue<long long int> q;
        q.push(k); sus[k] = true;
        while(!q.empty())
        {
            long long int curr = q.front();
            q.pop();
            for(int i=0; i<out[curr].size(); i++)
            {
                if(sus[out[curr][i]] == false)
                {
                    sus[out[curr][i]] = true;
                    q.push(out[curr][i]);
                }
            }
        }
        bool check = true;
        for(int i=0; i<n; i++)
        {
            if(sus[i] == true)
            {
                for(int j=0; j<in[i].size(); j++)
                {
                    if(sus[in[i][j]] == false) {check = false; break;}
                }
            }
            if(check == false) break;
        }
        vector<int> req;
        if(check == false) for(int i=0; i<n; i++) req.push_back(i);
        else for(int i=0; i<n; i++) if(sus[i] == false) req.push_back(i);
        return req;
    }
};