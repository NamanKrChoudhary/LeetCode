class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<long long int, long long int>>arr;
        for(int i=0; i<nums.size(); i++)
        {
            pair<long long int, long long int>p;
            p.second = i;
            for(int j=0; j<nums[i].size(); j++)
            {
                p.first = nums[i][j];
                arr.push_back(p);
            }
        }
        sort(arr.begin(), arr.end());
        multiset<pair<long long int, long long int>> s;
        map<long long int, long long int> mp;
        vector<int> ans(2);
        ans[0] = arr[0].first; 
        ans[1] = arr[arr.size()-1].first;
        for(int i=0,j=0; i<arr.size(); i++)
        {
            mp[arr[i].second]++;
            s.insert(arr[i]);
            while(mp[arr[j].second]>1 && j<=i)
            {
                auto it = s.find(arr[j]);
                s.erase(it);
                mp[arr[j].second]--;
                j = j+1;
            }
            if(mp.size() == nums.size())
            {
                auto endit = s.end(); endit--;
                auto begit = s.begin();
                long long int now = ((*endit).first)-((*begit).first);
                long long int curr = ans[1]-ans[0];
                if(curr > now) 
                {
                    ans[0]=(*begit).first;
                    ans[1] = (*endit).first;
                }
            }
        }
        return ans;
    }
};