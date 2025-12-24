class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long int n = nums.size();
        vector<long long int> pref(n);
        map<long long int, long long int> rem;
        pref[0] = nums[0]%p;
        for(int i=1; i<n; i++) pref[i] = (nums[i]+pref[i-1])%p;
        long long int req = pref[n-1];
        if(req == 0) return 0;
        long long int minn = n;
        for(int i=n-1; i>=0; i--)
        {
            //cout << (req-pref[i]+p)%p << " " << pref[i] << " " << req << " " << (req-pref[i]+p)%p << endl;
            if(rem.find((req+pref[i])%p) != rem.end()) minn = min(minn, rem[(req+pref[i])%p]-i);
            rem[pref[i]] = i; 
        }
        if(rem.find(req) != rem.end()) minn = min(minn, rem[req]+1);
        if(minn == n) return -1;
        else return minn;
    }
};