class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        long long int n = grid.size(), m = grid[0].size();
        long long int req = 0;
        for(int i=0; i<n-2; i++)
        {
            for(int j=0; j<m-2; j++)
            {
                bool check = true;
                long long int rowreq = 0;
                set<long long int> uniq;
                for(int r=0; r<3; r++)
                {
                    long long int temp = 0;
                    for(int c=0; c<3; c++)
                    {
                        if(grid[i+r][j+c] == 0 || grid[i+r][j+c] > 9) {check = false;}
                        temp = temp + grid[i+r][j+c];
                        uniq.insert(grid[i+r][j+c]);
                    }
                    if(rowreq == 0) rowreq = temp;
                    else if(rowreq != temp) check = false;
                }
                if(check == false || uniq.size() != 9) continue;
                for(int c=0; c<3; c++)
                {
                    long long int temp = 0;
                    for(int r=0; r<3; r++)
                    {
                        temp = temp + grid[i+r][j+c];
                    }
                    if(rowreq != temp) check = false;
                }
                if(check == false) continue;
                long long int temp = 0;
                for(int r=0; r<3; r++) temp = temp + grid[i+r][j+r];
                if(temp != rowreq) check = false;
                temp = 0;
                for(int r=2, c=0; c<3; r--, c++) temp = temp + grid[i+r][j+c];
                if(temp != rowreq) check = false;
                if(check) req = req + 1;
            }

        }
        return req;
    }
};