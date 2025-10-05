class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> vis1(n, vector<bool>(m, false)), vis2(n, vector<bool>(m, false));
        queue<pair<int, int>> q1, q2;
        vector<vector<pair<int, int>>> mark(heights.size(), vector<pair<int, int>>(heights[0].size(), {0,0 }));
        for(int i=0; i<n; i++)
        {
            q1.push({i,0});
            mark[i][0].first = 1;
            q2.push({i,m-1});
            mark[i][m-1].second = 1;
        }
        for(int i=0; i<m; i++)
        {
            q1.push({0,i});
            mark[0][i].first = 1;
            q2.push({n-1, i});
            mark[n-1][i].second = 1;
        }
        while(!q1.empty())
        {
            pair<int, int> curr = q1.front();
            q1.pop();
            if(curr.first-1 >= 0 && vis1[curr.first-1][curr.second] == false && heights[curr.first-1][curr.second] >= heights[curr.first][curr.second]) {vis1[curr.first-1][curr.second] = true; mark[curr.first-1][curr.second].first = 1; q1.push({curr.first-1, curr.second});}
            if(curr.first+1 < n && vis1[curr.first+1][curr.second] == false && heights[curr.first+1][curr.second] >= heights[curr.first][curr.second]) {vis1[curr.first+1][curr.second] = true; mark[curr.first+1][curr.second].first = 1; q1.push({curr.first+1, curr.second});}
            if(curr.second-1 >=0 && vis1[curr.first][curr.second-1] == false && heights[curr.first][curr.second-1] >= heights[curr.first][curr.second]) {vis1[curr.first][curr.second-1] = true; mark[curr.first][curr.second-1].first = 1; q1.push({curr.first, curr.second-1});}
            if(curr.second+1 <m && vis1[curr.first][curr.second+1] == false && heights[curr.first][curr.second+1] >= heights[curr.first][curr.second]) {vis1[curr.first][curr.second+1] = true; mark[curr.first][curr.second+1].first = 1; q1.push({curr.first, curr.second+1});}
        }
        while(!q2.empty())
        {
            pair<int, int> curr = q2.front();
            q2.pop();
            if(curr.first-1 >= 0 && vis2[curr.first-1][curr.second] == false && heights[curr.first-1][curr.second] >= heights[curr.first][curr.second]) {vis2[curr.first-1][curr.second] = true; mark[curr.first-1][curr.second].second = 1; q2.push({curr.first-1, curr.second});}
            if(curr.first+1 < n && vis2[curr.first+1][curr.second] == false && heights[curr.first+1][curr.second] >= heights[curr.first][curr.second]) {vis2[curr.first+1][curr.second] = true; mark[curr.first+1][curr.second].second = 1; q2.push({curr.first+1, curr.second});}
            if(curr.second-1 >=0 && vis2[curr.first][curr.second-1] == false && heights[curr.first][curr.second-1] >= heights[curr.first][curr.second]) {vis2[curr.first][curr.second-1] = true; mark[curr.first][curr.second-1].second = 1; q2.push({curr.first, curr.second-1});}
            if(curr.second+1 <m && vis2[curr.first][curr.second+1] == false && heights[curr.first][curr.second+1] >= heights[curr.first][curr.second]) {vis2[curr.first][curr.second+1] = true; mark[curr.first][curr.second+1].second = 1; q2.push({curr.first, curr.second+1});}
        }
        vector<vector<int>> res;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mark[i][j].first == 1 && mark[i][j].second == 1) res.push_back({i,j});
            }
        }
        return res;
    }
};