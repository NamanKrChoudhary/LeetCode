class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        multiset<long long int> ms;
        long long int n = nums.size();
        for(int i=0; i<k-1; i++) ms.insert(nums[i]);
        long long int minn = 1e9;
        for(int i=0,j=k-1; j<n; j++,i++)
        {
            ms.insert(nums[j]);
            minn = min(minn, *ms.rbegin()-*ms.begin());
            auto it = ms.find(nums[i]);
            ms.erase(it);
        }
        return minn;
    }
};