class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<long long int, long long int> mp;
        int n = nums.size();
        map<long long int, long long int> last;
        for(int i=0; i<n; i++) last[nums[i]] = -1;
        for(int i=0; i<n; i++)
        {
            long long int leftlimit = max(-1, i-k+1);
            leftlimit = max(leftlimit, last[nums[i]]);
            long long int rightlimit = min(n-1, i+k-1);
            long long int leftdist = max(i-leftlimit+1,0LL), rightdist = max(rightlimit-i+1, 0LL);
            if(leftlimit == last[nums[i]] && leftdist > 0) leftdist = leftdist -1;
            last[nums[i]] = i;
            long long int dist = (leftdist + rightdist - 1)-k+1;
            if(leftdist == 0) {leftdist = 1; dist = 1;}
            if(leftdist + rightdist -1 >= k) mp[nums[i]] = mp[nums[i]] + dist;
            // cout << i << endl;
            // cout << leftdist << " " << rightdist << " " << last[nums[i]] << " " << dist << endl;
        }
        //for(auto i: mp) cout << i.first << " " << i.second << endl;
        long long int req = -1;
        for(auto i: mp) if(i.second == 1) req = i.first;
        return req;
    }
};