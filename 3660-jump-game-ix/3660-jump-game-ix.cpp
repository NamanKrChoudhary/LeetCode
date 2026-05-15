class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
          int n = nums.size();
        vector<  int> maxarr(n);
          int currmax = nums[0];
        for(int i=0; i<n; i++)
        {
            currmax = max(currmax, nums[i]);
            maxarr[i] = currmax;
        }
        set<  int> s;
        map<  int,   int> mp;
        vector<  int> maxx(n);
        //for(int i=0; i<n; i++) cout << maxarr[i] << " "; cout << endl;
        for(int i=n-1; i>=0; i--)
        {
            auto it = s.lower_bound(maxarr[i]);
            maxx[i] = maxarr[i];
            if(it != s.begin())
            {
                it--;
                maxx[i] = max(maxx[i], mp[*it]);
                //cout << i << " " << *it << " " << mp[*it] << endl;
            }
            mp[nums[i]] = max(mp[nums[i]], maxx[i]);
            s.insert(nums[i]);
        }
        return maxx;
    }
};