//#include <numeric>

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 61; ++k) {
            long long target = num1 - k * num2;
            if (target < k) {
                if (num2 >= 0) break;
                if (target <= 0) continue;
            }
            if (__builtin_popcountll(target) <= k) {
                return k; // Found the smallest k that works
            }
        }
        return -1;
    }
};