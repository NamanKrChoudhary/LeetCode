class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        long long int n = matrix.size(), m = matrix[0].size();
        vector<vector<long long int>> pref(n, vector<long long int>(m));
        for(int j=0; j<m; j++)
        {
            long long int temp = 0;
            for(int i=n-1; i>=0; i--)
            {
                if(matrix[i][j] == 0) temp = 0;
                temp = temp + matrix[i][j];
                pref[i][j] = temp;
            }
        }
        long long int maxx = 0;
        for(int i=0; i<n; i++)
        {
            priority_queue<long long int> pq;
            for(int j=0; j<m; j++) pq.push(pref[i][j]);
            long long int sz = 1;
            long long int minn = 1e10;
            while(!pq.empty())
            {
                minn = min(minn, pq.top());
                pq.pop();
                maxx = max(maxx, (minn*sz));
                sz = sz + 1;
            }
        }
        return maxx;
    }
};