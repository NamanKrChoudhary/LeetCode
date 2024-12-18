class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long int lcm = b*(a/gcd(a,b));
        long long int s=0, e=1e14, mid = s+((e-s)/2);
        long long int dd = 1e9 + 7;
        long long int ans = 0;
        while(s<=e)
        {
            mid = s+((e-s)/2);
            long long int temp = (mid/a)+(mid/b)-(mid/lcm);
            if(temp >= n) {ans = mid%(dd); e = mid-1;}
            else s = mid+1;
        }
        return ans;
    }
};