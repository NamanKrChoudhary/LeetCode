class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        if(n > batteries.size()) return 0;
        vector<int> arr = batteries;
        sort(arr.rbegin(), arr.rend());
        long long int st = 0, end = 1e15, mid = st + ((end-st)/2);
        long long int req = 0;
        while(st <= end)
        {
            mid = st + ((end-st)/2);
            long long int cnt = 0;
            long long int cangive = 0;
            long long int curr = 0;
            cout << mid << endl;
            for(int i=0; i<batteries.size() && cnt < n;)
            {
                if(cangive == 0) cangive = batteries[i];
                long long int totake = min(cangive, mid-curr);
                long long int nextcangive = min(curr, cangive-totake);
                curr = curr + totake;
                cangive = nextcangive;
                // cout << i << " " << cangive << " " << curr << endl;
                // cout << totake << " " << nextcangive << endl;
                // cout << cnt << endl;
                if(cangive == 0) i = i + 1;
                if(curr == mid) {cnt = cnt + 1; curr = 0;}
            }
            if(cnt == n) {req = mid; st = mid + 1;}
            else end = mid-1;
        }
        return req;
    }
};