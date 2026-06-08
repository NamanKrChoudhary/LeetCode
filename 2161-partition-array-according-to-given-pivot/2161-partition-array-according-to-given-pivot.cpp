class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> less, eq, more, req;
        for(int i=0; i<n; i++)
        {
            if(nums[i] < pivot) less.push_back(nums[i]);
            else if(nums[i] > pivot) more.push_back(nums[i]);
            else eq.push_back(nums[i]);
        }
        for(auto i: less) req.push_back(i);
        for(auto i: eq) req.push_back(i);
        for(auto i: more) req.push_back(i);
        return req;
    }
};