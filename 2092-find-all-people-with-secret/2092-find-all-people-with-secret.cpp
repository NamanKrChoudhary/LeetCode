class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<long long int, long long int>>> arr(n);
        vector<bool> vis(n, false);
        set<pair<long long int, long long int>> s;
        for(int i=0; i<meetings.size(); i++)
        {
            arr[meetings[i][0]].push_back({meetings[i][2], meetings[i][1]});
            arr[meetings[i][1]].push_back({meetings[i][2], meetings[i][0]});
        }
        s.insert({0,0});
        s.insert({0,firstPerson});
        while(!s.empty())
        {
            pair<long long int, long long int> curr = *s.begin();
            s.erase(curr);
            long long int currtime = curr.first;
            long long int currelem = curr.second;
            if(!vis[currelem])
            {
                vis[currelem] = true;
                for(int i=0; i<arr[currelem].size(); i++) if(arr[currelem][i].first >= currtime) {s.insert(arr[currelem][i]);};
            }
        }
        vector<int> req;
        for(int i=0; i<n; i++) if(vis[i]) req.push_back(i);
        return req;
    }
};