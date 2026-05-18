class Solution {
public:
    int minJumps(vector<int>& arr) {
        long long int n = arr.size();
        map<long long int, vector<long long int>> mp;
        vector<long long int> vis(n, -1);
        for(int i=0; i<n; i++) mp[arr[i]].push_back(i);
        queue<pair<long long int, long long int>> q;
        q.push({0, 0}); vis[0] = 0; 
        // while(!q.empty())
        // {
        //     pair<long long int, long long int> curr = q.front();
        //     cout << curr.first << " " << curr.second << endl;
        //     q.pop();
        // }
        while(!q.empty())
        {
            pair<long long int, long long int> curr = q.front();
            q.pop();
            if(curr.first == n-1) 
            {
                //cout << curr.first << " " << curr.second << " " << vis[curr.first] << endl;
                break;
            }
            if(mp.find(arr[curr.first]) != mp.end())
            {
                //cout << curr.first << " " << curr.second << endl;
                
                for(auto i: mp[arr[curr.first]])
                {
                    if(vis[i] == -1)
                    {
                        vis[i] = curr.second + 1;
                        q.push({i, curr.second + 1});
                    }
                }
                mp.erase(arr[curr.first]);
            }
            if(curr.first+1 < n && vis[curr.first+1] == -1)
            {
                q.push({curr.first+1, curr.second+1});
                vis[curr.first+1] = curr.second+1;
                // for(auto i: mp[arr[curr.first+1]]) 
                // {
                //     if(vis[i] == -1)
                //     {
                //         //cout << i << " " << curr.first+1 << endl;
                //         q.push({i, curr.second + 2});
                //         vis[i] = curr.second+2;
                //     }
                // }
            }
            //cout << curr.first-1 << " " << curr.second << endl;
            if(curr.first-1 >= 0 && vis[curr.first-1] == -1)
            {
                q.push({curr.first-1, curr.second+1});
                vis[curr.first-1] = curr.second+1;
                // for(auto i: mp[arr[curr.first-1]]) 
                // {
                //     if(vis[i] == -1)
                //     {
                //         //cout << i << " " << curr.first-1 << endl;
                //         q.push({i, curr.second + 2});
                //         vis[i] = curr.second+2;
                //     }
                // }
            }
            //cout << q.size() << endl;
        }
        //for(auto i: vis) cout << i <<" "; cout << endl;
        return vis[n-1];
    }
};