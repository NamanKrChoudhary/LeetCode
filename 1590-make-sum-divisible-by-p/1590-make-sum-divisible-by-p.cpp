class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        typedef long long ll;
        int n = nums.size();
        ll total = 0;
        for (int x : nums)
            total += x;
        int target = total % p;
        if (target == 0)
            return 0;
        unordered_map<int, int> dic;
        dic[0] = -1;
        ll curr = 0;
        int res = n;
        for (int i = 0; i < n; i++){
            curr = (curr + nums[i]) % p;
            int need = (curr - target + p) % p;
            if (dic.count(need)){
                res = min(res, i - dic[need]);
            }
            dic[curr] = i;
        }
        return res == n ? -1 : res;
    }
};