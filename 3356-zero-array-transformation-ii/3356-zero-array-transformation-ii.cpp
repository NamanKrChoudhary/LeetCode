class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        bool ch = true;
        long long int n = nums.size();
        for(int i=0; i<nums.size(); i++) if(nums[i] != 0) {ch = false; break;}
        if(ch) return 0;
        long long int st = 1, end = queries.size(), mid = st + ((end-st)/2);
        long long int minn = -1;
        while(st <= end)
        {
            mid = st + ((end-st)/2);
            vector<long long int> add(n,0), sub(n, 0);
            for(int i=0; i<mid; i++)
            {
                add[queries[i][0]] += queries[i][2];
                sub[queries[i][1]] += queries[i][2];
            }
            ch = true;
            long long int curr = 0;
            for(int i=0; i<n; i++)
            {
                curr = curr + add[i];
                if(curr <  nums[i]) {ch = false; break;}
                curr = curr - sub[i];
            }
            if(ch)
            {
                if(minn == -1) minn = mid;
                else minn = min(mid, minn);
                end = mid-1;
            }
            else st = mid + 1;
        }
        return minn;
    }
};