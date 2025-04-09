class Solution {
public:

    bool mat(vector<vector<bool>>& vis, vector<vector<char>>& board, int curri, int currj)
    {
        vis[curri][currj] = true;
        bool check1 = true, check2 = true, check3 = true, check4 = true;
        if(curri<board.size()-1 && !vis[curri+1][currj] && board[curri+1][currj] == 'O') check1 = mat(vis, board, curri+1, currj);
        if(currj<board[0].size()-1 && !vis[curri][currj+1] && board[curri][currj+1] == 'O') check2 = mat(vis, board, curri, currj+1);
        if(curri>0 && !vis[curri-1][currj] && board[curri-1][currj] == 'O') check3 = mat(vis, board, curri-1, currj);
        if(currj>0 && !vis[curri][currj-1] && board[curri][currj-1] == 'O') check4 = mat(vis, board, curri, currj-1);
        if(curri == board.size()-1 || curri == 0 || currj == board[0].size()-1 || currj == 0) return false;
        if(check1 && check2 && check3 && check4)
        {
            //board[curri][currj] = 'X';
            return true;
        }
        else return false;
    }

    void change(vector<vector<bool>>& vis, vector<vector<char>>& board, int curri, int currj)
    {
        vis[curri][currj] = true;
        board[curri][currj] = 'X';
        //if(curri == board.size()-1 || curri == 0 || currj == board[0].size()-1 || currj == 0) return false;
        //bool check1 = false, check2 = false, check3 = false, check4 = false;
        if(curri<board.size()-1 && !vis[curri+1][currj] && board[curri+1][currj] == 'O') change(vis, board, curri+1, currj);
        if(currj<board[0].size()-1 && !vis[curri][currj+1] && board[curri][currj+1] == 'O') change(vis, board, curri, currj+1);
        if(curri>0 && !vis[curri-1][currj] && board[curri-1][currj] == 'O') change(vis, board, curri-1, currj);
        if(currj>0 && !vis[curri][currj-1] && board[curri][currj-1] == 'O') change(vis, board, curri, currj-1);
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size()));
        vector<vector<bool>> vis1(board.size(), vector<bool>(board[0].size()));
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                bool check = false;
                if(!vis[i][j] && board[i][j] == 'O') check = mat(vis, board, i, j);
                if(check) change(vis1, board, i, j);
            }
        }
        return;
    }
};