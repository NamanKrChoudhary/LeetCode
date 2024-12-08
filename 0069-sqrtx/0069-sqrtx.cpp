class Solution {
public:
    int mySqrt(int x) {
        long long int st = 0, end = x, mid = st + (end-st)/2;
        long long int prev = 0, curr = x;
        long long int ans = 0;
        while( st <= end)
        {
            mid = st + (end-st)/2;
            prev = curr;
            curr = mid;
            if(mid*mid < x) {st = mid +1; ans = mid;}
            else if( mid*mid > x) end = mid-1;
            else return mid;
        }
        return ans;
    }
};