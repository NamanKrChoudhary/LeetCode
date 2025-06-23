#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if x is a palindrome in base-k
    bool isPalindromeBaseK(long long x, int k) {
        vector<int> digs;
        while (x > 0) {
            digs.push_back(x % k);
            x /= k;
        }
        for (int l = 0, r = (int)digs.size() - 1; l < r; ++l, --r) {
            if (digs[l] != digs[r]) return false;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        vector<long long> result;
        long long sum = 0;
        
        // Generate palindromes by length
        for (int length = 1; result.size() < n; ++length) {
            int half = (length + 1) / 2;
            int start = half == 1 ? 1 : pow(10, half - 1);
            int end   = pow(10, half) - 1;

            for (int prefix = start; prefix <= end && result.size() < n; ++prefix) {
                string s = to_string(prefix);
                string t = s;
                if (length % 2 == 1) t.pop_back();
                reverse(t.begin(), t.end());

                long long pal = stoll(s + t);
                if (isPalindromeBaseK(pal, k)) {
                    result.push_back(pal);
                    sum += pal;
                }
            }
        }

        return sum;
    }
};
