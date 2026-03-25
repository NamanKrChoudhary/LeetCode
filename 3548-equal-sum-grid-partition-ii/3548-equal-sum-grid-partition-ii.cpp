class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long int n = grid.size(), m = grid[0].size();
        vector<long long int> rows(n), cols(m);
        for(int i=0; i<n; i++)
        {
            long long int temp = 0;
            for(int j=0; j<m; j++) temp = temp + grid[i][j];
            rows[i] = temp;
        }
        for(int j=0; j<m; j++)
        {
            long long int temp = 0;
            for(int i=0; i<n; i++) temp = temp + grid[i][j];
            cols[j] = temp;
        }
        long long int total = 0;
        for(int i=0; i<n; i++) total = total + rows[i];
        map<long long int, long long int> p1, p2;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) p2[grid[i][j]]++;
        long long int curr = 0;
        if(n == 1)
        {
            for(int j=0; j<m-1; j++)
            {
                curr = curr + grid[0][j];
                long long int next = total - curr;
                if(curr == next) return true;
                if(j > 0 && (curr-next == grid[0][0] || curr-next == grid[0][j])) return true;
                if(j < m-1 && (next-curr == grid[0][j+1] || next-curr == grid[0][m-1])) return true;
            }   
            return false; 
        }
        curr = 0;
        if(m == 1)
        {
            for(int i=0; i<n-1; i++)
            {
                curr = curr + grid[i][0];
                long long int next = total - curr;
                if(curr == next) return true;
                if(i > 0 && (curr-next == grid[0][0] || curr-next == grid[i][0])) return true;
                if(i < n-1 && (next-curr == grid[i+1][0] || next-curr == grid[n-1][0])) return true;
            }
            return false;
        }
        for(int i=0; i<n-1; i++)
        {
            curr = curr + rows[i];
            long long int next = total - curr;
            for(int j=0; j<m; j++)
            {
                p1[grid[i][j]]++;
                p2[grid[i][j]]--;
            }
            if(curr == next) return true;
            if(i==0)
            {
                if(curr-next == grid[i][0] || curr-next == grid[i][m-1]) return true;
            }
            if(i > 0)
            {
                if(p1.find(curr-next) != p1.end() && p1[curr-next] > 0) return true;
            }
            if(i<n-2)
            {
                if(p2.find(next-curr) != p2.end() && p2[next-curr] > 0) return true;
            }
            //cout << curr << " " << next << " " << total <<  endl;
            if(i == n-2)
            {
                if(next-curr == grid[i+1][0] || next-curr == grid[i+1][m-1]) return true;
            }
        }
        curr = 0;
        p1.clear(); p2.clear();
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) p2[grid[i][j]]++;
        for(int j=0; j<m-1; j++)
        {
            curr = curr + cols[j];
            long long int next = total - curr;
            // cout << j << endl;
            // cout << curr << " " << next <<  " " << total << endl;
            for(int i=0; i<n; i++)
            {
                p2[grid[i][j]]--;
                p1[grid[i][j]]++;
            }
            if(curr == next) return true;
            if(j==0)
            {
                if(curr-next == grid[0][j] || curr-next == grid[n-1][j]) return true;
            }
            if(j>0)
            {
                if(p1.find(curr-next) != p1.end() && p1[curr-next] > 0) return true;
            }
            if(j<m-2)
            {
                if(p2.find(next-curr) != p2.end() && p2[next-curr] > 0) return true;
            }
            if(j==m-2)
            {
                if(next-curr == grid[0][j+1] || next-curr == grid[n-1][j+1]) return true;
            }
            //cout << "here " << j <<endl;
        }
        return false;
        // 1 2
        // 3 4
    }
};