class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        long long int n = board.size();
        long long int tot = n*n;
        vector<vector<long long int>> grid(n ,vector<long long int>(n, -1));
        // {dice, curr}
        set<pair<long long int, long long int>> s;
        s.insert({0,0});
        while(!s.empty())
        {
            pair<long long int, long long int> curr = *s.begin(); s.erase(curr);
            long long int currdice = curr.first, currno = curr.second;
            if(currno == tot-1) break;
            for(int i=currno+1; i<=min(tot-1,currno+6); i++)
            {
                long long int temp = i;
                long long int nexti = n-1-(temp/n);
                long long int nextj = temp%n;
                if((i/n)%2 == 1) nextj = n-1-nextj;
                if(board[nexti][nextj] != -1) 
                {
                    temp = board[nexti][nextj]-1;
                    nexti = n-1-(temp/n);
                    nextj = temp%n;
                    if((temp/n)%2 == 1) nextj = n-1-nextj;
                }
                if(grid[nexti][nextj] != -1) continue;
                s.insert({currdice+1, temp});
                grid[nexti][nextj] = currdice+1;
            }
        }
        long long int last = n-1;
        if(n%2 == 0) last = 0;
        return grid[0][last];
    }
};