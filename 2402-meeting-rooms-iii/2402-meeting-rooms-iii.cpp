class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<vector<long long int>> meets;
        for(int i=0; i<meetings.size(); i++)
        {
            vector<long long int> temp = {meetings[i][0], meetings[i][1]};
            meets.push_back(temp);
        }
        sort(meets.begin(), meets.end());
        vector<long long int> curr(n,-1);
        vector<long long int> nos(n,0);
        for(long long int i=0; i<meets.size(); i++)
        {
            long long int minn = LLONG_MAX;
            long long int mini = -1;
            for(long long int j=0; j<n; j++)
            {
                if(minn > curr[j]) {minn = curr[j]; mini = j; if(minn <= meets[i][0]) break;}
            } 
            if(minn <= meets[i][0]) {nos[mini]++; curr[mini] = meets[i][1];}
            else
            {
                long long int len = meets[i][1]-meets[i][0];
                minn = max(minn+len, meets[i][1]);
                curr[mini] = minn;
                nos[mini]++;
            }
        }
        long long int maxx = 0;
        long long int maxi = 0;
        for(long long int i=0; i<n; i++) if(maxx < nos[i]){maxx = nos[i]; maxi = i;}
        return maxi;
    }
};