class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        long long int n = grid.size(), m = grid[0].size();
        vector<vector<int>> arr(n, vector<int>(m));
        long long int a = 0, b = 0, c = m-1, d = n-1;
        while(a<=c && b <=d)
        {
            long long int len = c-a+1, bre = d-b+1;
            long long int tot = (2*len)+(2*bre)-4;
            long long int rot = k%tot;
            long long int i = 1, j = i+rot;
            //cout << len << " " << bre << " " << tot << endl;
            for(; i<=tot; i=i+1 ,j=j+1)
            {
                if(j > tot) j = (j%tot);
                long long int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
                if(i <= len-1)
                {
                    x1 = b;
                    y1 = a + (i-1);
                }
                else if(i >= (len-1) + 1 && i <= (len-1)+(bre-1))
                {
                    y1 = c;
                    x1 = b + (i-(len-1))-1;
                }
                else if(i >= (len-1)+(bre-1)+1 && i <= 2*(len-1)+(bre-1))
                {
                    x1 = d;
                    y1 = c - (i-((len-1)+(bre-1))) +1;
                }
                else
                {
                    y1 = a;
                    x1 = d - (i - ((2*(len-1))+(bre-1))) + 1;
                }

                if(j <= len-1)
                {
                    x2 = b;
                    y2 = a + (j-1);
                }
                else if(j >= (len-1) + 1 && j <= (len-1)+(bre-1))
                {
                    y2 = c;
                    x2 = b + (j-(len-1))-1;
                }
                else if(j >= (len-1)+(bre-1)+1 && j <= (2*(len-1))+(bre-1))
                {
                    x2 = d;
                    y2 = c - (j-((len-1)+(bre-1))) +1;
                }
                else
                {
                    y2 = a;
                    x2 = d - (j - ((len-1)+(bre-1)+(len-1))) + 1;

                }
                // cout << i << " " << j << endl;
                // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                arr[x1][y1] = grid[x2][y2];
            }
            a = a+1; b = b+1; c = c-1; d = d-1;
        }
        return arr;
    }
};