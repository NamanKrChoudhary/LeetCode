class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<long long int, long long int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;
        vector<pair<long long int, long long int>> p;
        for(auto i: mp) p.push_back(i);
        if(p.size() == 1) return 0;
        long long int check = 0;
        for(int i=1; i<p.size(); i++)
        {
            if(p[i-1].first+1 == p[i].first) check = max(check, (p[i-1].second+p[i].second));
        }
        return check;
    }
};