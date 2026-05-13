class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<vector<long long int>> arr;
        long long int n = nums.size();
        map<long long int, long long int> mp;
        for(int i=0, j=n-1; i<n/2; i++, j--)
        {
            arr.push_back({min(nums[i],nums[j])+1, 1});
            arr.push_back({max(nums[i], nums[j])+limit, 3});
            if(mp.find(nums[i]+nums[j]) == mp.end()) arr.push_back({nums[i]+nums[j], 2});
            mp[nums[i]+nums[j]]++;
        }
        sort(arr.begin(), arr.end());
        long long int on = 0;
        long long int req = n;
        for(int i=0; i<arr.size(); i++)
        {
            //cout << arr[i][0] << " " << arr[i][1] << endl;
            if(arr[i][1] == 1) 
            {
                on = on + 1;
                if(on == n/2) req = min(req, n/2);
            }
            else if(arr[i][1] == 3) on = on -1;
            else
            {
                long long int onplace = mp[arr[i][0]];
                long long int inbound = on - onplace;
                long long int outbound = (n/2)-(on);
                long long int moves = inbound + (2*outbound);
                req = min(req, moves);
            }
        }
        return req;
    }
};