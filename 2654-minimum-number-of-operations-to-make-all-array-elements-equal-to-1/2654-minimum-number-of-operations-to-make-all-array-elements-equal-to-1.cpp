#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        long long int n = nums.size();
        long long int cnt1 = 0;
        for(int i=0; i<n; i++) if(nums[i] == 1) cnt1 = cnt1 + 1;
        if(cnt1 > 0) return n-cnt1;
        long long int minn = n+1;
        for(int i=0; i<n; i++)
        {
            int gc = nums[i];
            for(int j=i; j<n; j++)
            {
                gc = __gcd(gc, nums[j]);
                if(gc == 1)
                {
                    long long int sz = j-i+1;
                    minn = min(minn, sz);
                    break;
                }
            }
        }
        if(minn == n+1) return -1;
        return n-1+(minn-1);
    }
};