class Solution {
public:
    int kthDigit(long long k) {
        //long long int currtens = 10;
        long long int st = 1, end = 1e15, mid = st + ((end-st)/2);
        long long int req = -1;
        long long int reqmid = -1;
        long long int cnt = -1;
        long long int cntdigs = -1;
        while(st <= end)
        {
            mid = st + ((end-st)/2);
            long long int currtens = 1;
            long long int currcntdigs = 1;
            long long int totcntdigs = 0;
            while(mid/currtens > 9)
            {
                totcntdigs = totcntdigs + (currcntdigs*9*currtens);
                currtens = currtens*10;
                currcntdigs = currcntdigs + 1;
            }
            totcntdigs = totcntdigs + (currcntdigs*(mid-currtens+1));
            if(totcntdigs >= k) {req = mid; reqmid = mid; cnt = totcntdigs; cntdigs = currcntdigs; end = mid-1;}
            else st = mid + 1;
        }
        if(k <= 9) return k;
        if((reqmid/10)%2 == 1)
        {
            long long int ones = reqmid%10;
            reqmid = reqmid/10;
            reqmid = reqmid*10;
            reqmid = reqmid + (9-ones);
        }
        vector<long long int> digs;
        while(reqmid)
        {
            digs.push_back(reqmid%10);
            reqmid = reqmid/10;
        }
        reverse(digs.begin(), digs.end());
        long long int reqind = k-(cnt - cntdigs);
        return digs[reqind-1];
    }
};