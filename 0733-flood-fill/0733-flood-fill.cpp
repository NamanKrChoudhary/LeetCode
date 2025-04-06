class Solution {
public:
    void dfs(vector<vector<bool>>& vis, vector<vector<int>>& image, int curri, int currj, int clr, int iclr)
    {
        vis[curri][currj] = true;
        if(curri>0 && !vis[curri-1][currj] && image[curri-1][currj] == iclr) dfs(vis, image, curri-1, currj, clr, iclr);
        if(currj>0 && !vis[curri][currj-1] && image[curri][currj-1] == iclr) dfs(vis, image, curri, currj-1, clr, iclr);
        if(curri<image.size()-1 && !vis[curri+1][currj] && image[curri+1][currj] == iclr) dfs(vis, image, curri+1, currj, clr, iclr);
        if(currj<image[0].size()-1 && !vis[curri][currj+1] && image[curri][currj+1] == iclr) dfs(vis, image, curri, currj+1, clr, iclr);
        image[curri][currj] = clr;
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size(), m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        int iclr = image[sr][sc];
        dfs(vis, image, sr, sc, color, iclr);
        return image;
    }
};