class Solution {
public:
    long long int modexp(long long int a, long long int b)
    {
        long long int res = 1;
        //cout << a << " " << b << endl;
        while(b)
        {
            if(b%2 == 1) res = res*a;
            //cout << res << endl;
            if(b > 1) a = a*a;
            b = b/2;
            if(a > 1e9 || res > 1e9) return -1;
        }
        return res;
    }
    int maximumLength(vector<int>& nums) {
        vector<long long int> powers;
        long long int curr = 1;
        long long int n = nums.size();
        while(curr <= 70)
        {
            powers.push_back(curr);
            curr = curr*2;
        }
        sort(nums.begin(), nums.end());
        map<long long int, long long int> mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;
        long long int maxx = 1;
        if(mp.find(1) != mp.end()) maxx = mp[1];
        if(maxx%2 == 0) maxx = maxx-1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 1) continue;
            long long int currsize = 1;
            if(mp[nums[i]] < 2) {continue;}
            for(int j=1; j<powers.size(); j++)
            {
                long long int curr = modexp(nums[i], powers[j]);
                //cout << i << " " << powers[j] << " " << curr << " " << currsize << endl;
                if(curr == -1) break;
                if(mp.find(curr) != mp.end())
                {
                    currsize = currsize + 2;
                    if(mp[curr] < 2) break; 
                }
                else break;
            }
            maxx = max(maxx, currsize);
        }
        return maxx;
    }
};