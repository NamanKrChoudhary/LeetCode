class Solution {
public:
    int countTriples(int n) {
        long long int cnt = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                int c = i*i;
                int b = j*j;
                int a = c-b;
                int sqa = sqrt(a);
                if((sqa*sqa)+b == c) cnt = cnt + 1;
            }
        }
        return cnt;
    }
};