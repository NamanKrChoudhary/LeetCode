class Solution {
public:
    const long long int mod = 1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        long long int n = board.size();
        vector<vector<long long int>> maxx(n, vector<long long int>(n, -1));
        maxx[n-1][n-1] = 0;
        board[0][0] = '0';
        board[n-1][n-1] = '0';
        for(int i=n-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(board[i][j] != 'X')
                {
                    if(i < n-1 && j< n-1 && board[i+1][j+1] != 'X') maxx[i][j] = max(maxx[i][j], maxx[i+1][j+1]);
                    if(i < n-1 && board[i+1][j] != 'X') maxx[i][j] = max(maxx[i][j], maxx[i+1][j]);
                    if(j < n-1 && board[i][j+1] != 'X') maxx[i][j] = max(maxx[i][j], maxx[i][j+1]);
                    if(maxx[i][j] != -1) maxx[i][j] = maxx[i][j] + (board[i][j]-'0');
                }
            }
        }
        if(maxx[0][0] == -1) return {0,0};
        vector<vector<long long int>> ways(n, vector<long long int>(n, 0));
        ways[n-1][n-1] = 1;
        board[0][0] = '0';
        board[n-1][n-1] = '0';
        for(int i=n-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(board[i][j] != 'X')
                {
                    if(i < n-1 && j< n-1 && board[i+1][j+1] != 'X' && maxx[i][j]-(board[i][j]-'0') == maxx[i+1][j+1]) ways[i][j] = (ways[i][j] + ways[i+1][j+1])%mod;
                    if(i < n-1 && board[i+1][j] != 'X' && maxx[i][j]-(board[i][j]-'0') == maxx[i+1][j]) ways[i][j] = (ways[i][j] + ways[i+1][j])%mod;
                    if(j < n-1 && board[i][j+1] != 'X' && maxx[i][j]-(board[i][j]-'0') == maxx[i][j+1]) ways[i][j] = (ways[i][j] + ways[i][j+1])%mod;
                    //if(i != 0 || j != 0) maxx[i][j] = maxx[i][j] + (board[i][j]-'0');
                }
            }
        }
        for(int i=0; i<n; i++) {for(int j=0; j<n; j++) cout << maxx[i][j] << " "; cout << endl;}
        cout << endl;
        for(int i=0; i<n; i++) {for(int j=0; j<n; j++) cout << ways[i][j] << " "; cout << endl;}
        return {(int)maxx[0][0], (int)ways[0][0]};

    }
};