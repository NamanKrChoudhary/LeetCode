class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,-1));
        bool check1 = false, check2 = false;
        if(n>1 && grid[1][0] > 1) check1 = true;
        if(m>1 && grid[0][1] > 1) check2 = true;
        if(check1 && check2) return -1;
        set<vector<int>> s;
        s.insert({0,0,0}); vis[0][0] = 0;
        vector<int> row = {-1, 0, 1, 0}, col = {0, 1, 0, -1};
        while(!s.empty())
        {
            vector<int> curr = *s.begin();
            auto it = s.find(curr);
            s.erase(it);
            int curri = curr[1], currj = curr[2], currval = curr[0];
            for(int i=0; i<4; i++)
            {
                int nexti = curri + row[i], nextj = currj + col[i];
                if(nexti < n && nextj < m && nexti >= 0 && nextj >= 0)
                {
                    int nextval = currval + 1;
                    if(nextval < grid[nexti][nextj]) nextval = currval + (((grid[nexti][nextj]-currval)/2)*2)+1;
                    if(vis[nexti][nextj] == -1 || nextval < vis[nexti][nextj])
                    {
                        s.erase({vis[nexti][nextj], nexti, nextj});
                        s.insert({nextval, nexti, nextj});
                        vis[nexti][nextj] = nextval;
                    }
                }
            }
        }
        return vis[n-1][m-1];
    }
};