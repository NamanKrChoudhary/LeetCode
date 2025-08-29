class Solution {
public:
    long long flowerGame(int n, int m) {
        long long int odd1 = 0, even1 = 0, odd2 = 0, even2 = 0;
        for(int i=1; i<=n; i++)
        {
            if(i%2 == 1) odd1 = odd1 + 1;
            else even1 = even1 + 1;
        }
        for(int i=1; i<=m; i++)
        {
            if(i%2 == 1) odd2 = odd2 + 1;
            else even2 = even2 + 1;
        }
        long long int ways = (odd1*even2) + (even1*odd2);
        return ways;
    }
};