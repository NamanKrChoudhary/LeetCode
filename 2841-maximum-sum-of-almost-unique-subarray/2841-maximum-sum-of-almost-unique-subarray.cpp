class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long int n = nums.size();
        long long int sum = 0;
        set<long long int> s; multiset<long long int> ms;
        for(int i=0; i<k; i++) 
        {
            s.insert(nums[i]);
            ms.insert(nums[i]);
            sum = sum + nums[i];
        }
        long long int maxx = 0;
        if(s.size() >= m) maxx = sum;
        for(int i=0,j=k; j<n; i++,j++)
        {
            auto it = ms.find(nums[i]);
            ms.erase(it);
            if(ms.find(nums[i]) == ms.end()) s.erase(nums[i]);
            sum = sum-nums[i];
            ms.insert(nums[j]);
            s.insert(nums[j]);
            sum = sum + nums[j];
            if(s.size() >= m) maxx = max(maxx, sum);
        }
        return maxx;
    }
};