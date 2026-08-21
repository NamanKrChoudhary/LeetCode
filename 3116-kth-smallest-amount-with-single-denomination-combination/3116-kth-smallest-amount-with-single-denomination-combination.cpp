class Solution {
public:
    void filler(vector<int>& coins, long long int mid, vector<long long int>& tot, long long int currlcm, long long int curri, long long int currcnt)
    {
        if(curri >= coins.size()) return;
        for(int i = curri; i<coins.size(); i++)
        {
            long long int currcoin = coins[i];
            long long int templcm = currcoin;
            if(currcnt > 1)
            {
                long long int nume = currcoin;
                if(currlcm != 0) nume = nume*currlcm; 
                templcm = nume/__gcd(currlcm, currcoin);
            }
            long long int curr = mid/templcm;
            //if(mid%templcm == 0) curr = curr + 1;
            if(currcnt%2 == 0) curr = curr*(-1);
            tot[0] = tot[0] + curr;
            //cout << mid << " " << curr << " " << templcm << " " << i  << " " << currlcm << " " << currcnt << " " << currcoin << endl;
            filler(coins, mid, tot, templcm, i+1, currcnt+1);
        }
        return;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        long long int currk = k, initcoins = coins[0];
        long long int st = 1, end = currk*initcoins, mid = st + ((end-st)/2);
        long long int req = 0;
        while(st <= end)
        {
            mid = st + ((end-st)/2);
            vector<long long int> cnt = {0};
            filler(coins, mid, cnt, 0, 0, 1);
            //if(cnt[0] == k) {req = mid; break;}
            if(cnt[0] < k) {st = mid + 1;}
            else {req = mid; end = mid-1;}
            //cout << mid << " " << cnt[0] << endl;
        }
        return req;
    }
    // 2 4 6 8 10
};