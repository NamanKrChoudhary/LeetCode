class Solution {
public:
    int health(vector<vector<int>>& dp, vector<vector<int>>& mat, int curri, int currj)
    {
        if(curri == mat.size()-1 && currj == mat[curri].size()-1) return dp[curri][currj] = max(0, -mat[curri][currj]);
        if(curri >= mat.size()) return INT_MAX;
        if(currj >= mat[curri].size()) return INT_MAX;
        if(dp[curri][currj] != -1) return dp[curri][currj];
        int right = health(dp, mat, curri, currj+1);
        int down = health(dp, mat, curri+1, currj);
        dp[curri][currj] = min(right, down) - mat[curri][currj];
        if(dp[curri][currj] < 0) dp[curri][currj] = 0;
        return dp[curri][currj];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // subproblem - the minimum health required by a smaller matrix.
        // state - dp[i][j] - the minimum health required to reach n,n;
        // transitions - dp[i][j] = min(dp[i+1][j], dp[j][j+1]) - mat[i][j] -> as the minimum health required for the hero so that it doesnt fall below zero
        // is taken from this, the minimum health required to reach the next possible stages, and if we see that the value of each of the cell is to be subtracted
        // to get the needed value - as if the cell is -ve the required minimum goes up, and if the cell is +ve, then the required minimum hp goes down.
        // if the required hp goes below 0 then that must be miantained at zero cuz that means the hero has many healing orbs and even if he started the 
        // journey with -ve hp, he would survive till last, but since it is not allowed to go below or equal to zero, we are taking the case when the hero would 
        // touch zero and then add one to ensure that case doesnt happen.

        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), -1));
        int minhp = health(dp, dungeon, 0, 0);
        return minhp+1;
    }
};