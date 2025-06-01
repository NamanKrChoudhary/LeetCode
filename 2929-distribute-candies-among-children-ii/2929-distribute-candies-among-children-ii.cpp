class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long int ans = 0;
        for(int i=0; i<=limit; i++)
        {
            long long int rem = n-i;
            long long int minn = rem/2;
            if(rem%2 == 1) minn = minn + 1;
            if(minn > limit) continue;
            long long int maxpos = min(limit, int(rem));
            long long int minpos = max(int(rem-limit), 0);
            ans = ans + (maxpos-minpos)+1;
        }
        return ans;
    }
};