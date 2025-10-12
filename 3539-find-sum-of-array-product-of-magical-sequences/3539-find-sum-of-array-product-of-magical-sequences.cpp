class Solution {
public:
    const long long int mod = 1e9+7;
    long long int modexp(long long int a, long long int b)
    {
        long long int res = 1;
        while(b)
        {
            if(b%2 == 1) res = (res*a)%mod;
            b = b/2;
            a = (a*a)%mod;
        }
        return res;
    }
    
    long long int filler(vector<int>& nums, vector<long long int>& fact, vector<long long int>& invfact, map<vector<long long int>, long long int>& dp, long long int curri, long long int remel, long long int remk, long long int carry)
    {
        if(dp.find({curri, remel, remk, carry}) != dp.end()) return dp[{curri, remel, remk, carry}];
        if(remel == 0)
        {
            if(__builtin_popcountll(carry) == remk) return 1;
            else return 0;
        }
        if((remk == 0 && remel > 0) || (curri >= nums.size() && remel > 0)) return 0;
        long long int sum = 0;
        for(int i=0; i<=remel; i++)
        {
            long long int curr = carry + i;
            long long int currk = remk;
            if(curr%2 == 1) currk = currk-1;
            long long int currm = remel - i;
            long long int temp = filler(nums, fact, invfact, dp, curri+1, currm, currk, curr/2);
            long long int tomul = modexp(nums[curri], i);
            tomul = (((((fact[remel]*invfact[i])%mod)*invfact[remel-i])%mod)*tomul)%mod;
            temp = (temp*tomul)%mod;
            sum = (sum + temp)%mod;
        }
        return dp[{curri, remel, remk, carry}] = sum;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        vector<long long int> fact(m+1);
        vector<long long int> invfact(m+1);
        fact[0] = 1;
        for(int i=1; i<=m; i++) fact[i] = (fact[i-1]*i)%mod;
        invfact[m] = modexp(fact[m], mod-2);
        for(int i=m-1; i>=0; i--) invfact[i] = (invfact[i+1]*(i+1))%mod;
        map<vector<long long int>, long long int> dp;
        return filler(nums, fact, invfact, dp, 0, m, k, 0);
    }
};