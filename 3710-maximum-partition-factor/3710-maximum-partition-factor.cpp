class Solution {
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        long long int n = points.size();
        if(n < 3) return 0;
        long long int st = 0, end = 1e9, mid;
        long long int maxx = 0;
        while(st <= end)
        {
            mid = st + ((end-st)/2);
            //cout << mid << endl;
            vector<vector<long long int>> adj(n);
            for(int i=0; i<n; i++)
            {
                long long int x = points[i][0], y = points[i][1];
                for(int j=i+1; j<n; j++)
                {
                    long long int currx = points[j][0], curry = points[j][1];
                    if(abs(x-currx) + abs(y-curry) < mid)
                    {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
            vector<long long int> part(n, 0);
            bool check = true;
            for(int k=0; k<n; k++)
            {
                if(part[k] == 0)
                {
                    queue<long long int> q;
                    q.push(k); part[k] = 1;
                    long long int next = 2;
                    while(!q.empty())
                    {
                        long long int len = q.size();
                        for(int i=0; i<len; i++)
                        {
                            long long int curr = q.front();
                            q.pop();
                            for(int j=0; j<adj[curr].size(); j++)
                            {
                                long long int ind1 = curr, ind2 = adj[curr][j];
                                if(part[ind2] != next && part[ind2] != 0) {check = false; break;}
                                if(part[ind2] == 0)
                                {
                                    part[ind2] = next;
                                    q.push(ind2);
                                }
                            }
                            if(check == false) break;
                        }
                        if(check == false) break;
                        if(next == 1) next = 2;
                        else next = 1;
                    }
                    if(check == false) break;
                }
            }
            //cout << mid << endl;
            //if(mid == 4) {for(int i=0; i<n; i++) {for(int j=0; j<adj[i].size(); j++) cout << adj[i][j] << " "; cout << endl;}}
            if(check == false) {end = mid-1;}
            else {maxx = mid; st = mid+1;}
        }
        return maxx;
    }
};