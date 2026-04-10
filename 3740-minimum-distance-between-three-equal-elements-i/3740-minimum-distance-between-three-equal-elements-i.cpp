class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<long long int, vector<long long int>> mp;
        long long int n = nums.size();
        for(int i=0; i<n; i++) mp[nums[i]].push_back(i);
        long long int minn = n;
        for(auto i: mp)
        {
            long long int end = (i.second).size();
            for(long long int j=2; j<end; j++) minn = min(minn, ((i.second)[j] - (i.second)[j-2]));
        }
        if(minn == n) return -1;
        else return (minn*2);
    }
};