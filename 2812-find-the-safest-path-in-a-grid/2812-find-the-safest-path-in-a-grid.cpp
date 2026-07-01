class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        long long int n = grid.size();
        vector<vector<int>> nearest(n, vector<int>(n, 1e9));
        for(int i=0; i<n; i++)
        {
            int prev = -1;
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1) prev = j;
                if(prev != -1) nearest[i][j] = j-prev;
            }
            prev = -1;
            for(int j=n-1; j>=0; j--)
            {
                if(grid[i][j] == 1) prev = j;
                if(prev != -1) nearest[i][j] = min(nearest[i][j], prev-j);
            }
        }
        for(int j=0; j<n; j++)
        {
            for(int i=1; i<n; i++)
            {
                nearest[i][j] = min(nearest[i][j], nearest[i-1][j]+1);
            }
            for(int i=n-2; i>=0; i--)
            {
                nearest[i][j] = min(nearest[i][j], nearest[i+1][j]+1);
            }
        }
        //for(int i=0; i<n; i++) {for(int j=0; j<n; j++) cout << nearest[i][j] << " "; cout << endl;}
        priority_queue<vector<int>> pq;
        pq.push({nearest[0][0], 0, 0});
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;
        vector<int> dr = {0, -1, 0, 1};
        vector<int> dc = {-1, 0, 1, 0};
        long long int req = 0;
        while(!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();
            if(curr[1] == n-1 && curr[2] == n-1) {req = curr[0]; break;}
            for(int i=0; i<4; i++)
            {
                //cout << curr[1] << " " << curr[2] << " " << i << endl;
                int nexti = curr[1]+dr[i];
                int nextj = curr[2]+dc[i];
                if(nexti < n && nexti >= 0 && nextj < n && nextj >= 0 && !vis[nexti][nextj])
                {
                    vis[nexti][nextj] = true;
                    pq.push({min(curr[0], nearest[nexti][nextj]), nexti, nextj});
                }
            }
        }
        return req;
    }
};