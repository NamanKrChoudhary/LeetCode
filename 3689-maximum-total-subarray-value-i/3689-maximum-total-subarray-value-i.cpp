class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long int n = nums.size();
        multiset<long long int> minn;
        multiset<long long int> maxx;
        for(int i=0; i<n; i++)
        {
            minn.insert(nums[i]);
            maxx.insert(nums[i]);
        }
        long long int val = ((*maxx.rbegin())) - (*minn.begin());
        // for(int i=k, j=0; i<n; i++,j++)
        // {
        //     auto it1 = maxx.find(nums[j]);
        //     maxx.erase(it1);
        //     auto it2 = minn.find(nums[j]);
        //     minn.erase(it2);
        //     maxx.insert(nums[i]);
        //     minn.insert(nums[i]);
        //     long long int temp = (*maxx.rbegin()) - (*minn.begin());
        //     val = max(val, temp);
        // }
        return k*val;
    }
};