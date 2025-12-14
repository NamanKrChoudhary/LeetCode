class Solution {
public:
    const long long int mod = 1e9+7;
    int numberOfWays(string corridor) {
        long long int n = corridor.size();
        long long int req = 1;
        long long int cnt = 0;
        long long int currway = 1;
        //long long int phatta = 1;
        for(int i=0; i<n; i++)
        {
            if(cnt < 2 && corridor[i] == 'P') continue;
            if(corridor[i] == 'S' && cnt < 2) {cnt = cnt + 1; continue;}
            if(corridor[i] == 'S' && cnt == 2) {req = (req*currway)%mod; currway = 1; cnt = 1;}
            if(corridor[i] == 'P' && cnt == 2) currway = currway + 1;
        }
        //cout << req << endl;
        if(cnt < 2) return 0;
        else return req;
    }
};