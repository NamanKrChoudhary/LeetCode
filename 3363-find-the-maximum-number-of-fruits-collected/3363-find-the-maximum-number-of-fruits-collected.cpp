class Solution {
public:
    // state - dp[i][j] = the maximum amt a child can collect while reaching the n,n and also considering
    // n-1 moves, both the children wont meet and one child can only move till the diagonal, or below it else it wont be able to reach the n,n in the specified moves

    int maxnumni(vector<vector<int>>& grid, vector<vector<int>>& dp, int curri, int currj)
    {
        if(currj > curri) return 0;
        if(dp[curri][currj] != -1) return dp[curri][currj];
        if(curri == grid.size()-1 && currj == grid.size()-1) dp[curri][currj] = grid[curri][currj];
        else if(curri == currj) dp[curri][currj] = grid[curri][currj] + maxnumni(grid, dp, curri+1, currj+1);
        else
        {
            int curr1 = 0, curr2 = 0, curr3 = 0;
            if(curri < grid.size()-1) curr1 = maxnumni(grid, dp, curri+1, currj+1);
            curr2 = maxnumni(grid, dp, curri, currj+1);
            curr3 = maxnumni(grid, dp, curri-1, currj+1);
            dp[curri][currj] = grid[curri][currj] + max(curr1, max(curr2, curr3));
        }
        return dp[curri][currj];
    }

    int maxnumin(vector<vector<int>>& grid, vector<vector<int>>& dp, int curri, int currj)
    {
        if(curri > currj) return 0;
        if(dp[curri][currj] != -1) return dp[curri][currj];
        else if(curri == grid.size()-1 && currj == grid.size()-1) return dp[curri][currj] = grid[curri][currj];
        else if(curri == currj) return dp[curri][currj] = grid[curri][currj] + maxnumin(grid, dp, curri+1, currj+1);
        else
        {
            int curr1 = 0, curr2 = 0, curr3 = 0;
            if(currj < grid.size()-1) curr1 = maxnumin(grid, dp, curri+1, currj+1);
            curr2 = maxnumin(grid, dp, curri+1, currj);
            curr3 = maxnumin(grid, dp, curri+1, currj-1);
            dp[curri][currj] = grid[curri][currj] + max(curr1, max(curr2, curr3));
        }
        return dp[curri][currj];
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int maxx = 0;
        vector<vector<int>> grid(n, vector<int>(n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == j) maxx = maxx + fruits[i][j];
                if(i != j) grid[i][j] = fruits[i][j];
            }
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int lchild = maxnumni(grid, dp, n-1, 0);
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) dp[i][j] = -1;
        int rchild = maxnumin(grid, dp, 0, n-1);
        return maxx + lchild + rchild;
    }
};