class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long int>> dist(n, vector<long long int>(n));
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) {dist[i][j] = LLONG_MAX; if(i == j) dist[i][j] = 0;}
        for(int i=0; i<edges.size(); i++)
        {
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX)
                    {
                        dist[i][j] = min(dist[i][j], (dist[i][k]+dist[k][j]));
                    }
                }
            }
        }
        long long int comp = distanceThreshold;
        long long int ans = -1, minn = n;
        for(int i=0; i<n; i++)
        {
            long long int temp = 0;
            for(int j=0; j<n; j++) if(i != j && dist[i][j] <= comp) {temp = temp+1;}
            if(temp == minn) ans = i;
            else if(temp < minn)
            {
                minn = temp;
                ans = i;
            }
        }
        return ans;
    }
};