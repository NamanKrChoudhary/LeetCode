class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> temp;
        for(int i=0; i<nums.size(); i++) temp.push_back({nums[i],i});
        sort(temp.rbegin(), temp.rend());
        vector<pair<int, int>> sum;
        for(int i=0; i<k; i++) sum.push_back({temp[i].second, temp[i].first});
        vector<int> ans;
        sort(sum.begin(), sum.end());
        for(auto i: sum) ans.push_back(i.second);
        return ans;
    }
};