class Solution {
public:
    int what(vector<int>&nums, vector<vector<int>>&arr , pair<int, int> remc, int i)
    {
        if(i > nums.size()) return 0;
        else if(i == nums.size()) return max(nums[remc.first], nums[i-1]);
        if(arr[i][remc.first] != -1) return arr[i][remc.first];
        if(i == nums.size()-1)
        {
            int r3 = max(nums[i], nums[i-1]) + nums[remc.first],
            r1 =  max(nums[remc.first], nums[i]) + nums[i-1],
            r2 = max(nums[remc.first], nums[i-1]) + nums[i],
            aa = min(min(r3 , r1), r2);
            arr[i][remc.first] = aa;
            return aa;
        }
        if(arr[i][remc.first] != -1) return arr[i][remc.first];
        pair<int, int> p1 = {remc.first, max(nums[i], nums[i-1])},
        p2 = {i, max(nums[i-1], nums[remc.first])},
        p3 = {i-1, max(nums[i], nums[remc.first])};
        int l1 = max(nums[i], nums[i-1]) + what(nums, arr, p1, i+2), l2 = max(nums[remc.first], nums[i-1]) + what(nums, arr, p2, i+2), l3 = max(nums[remc.first], nums[i]) + what(nums, arr , p3, i+2);
        int aa = min(min(l1 , l2), l3);
        arr[i][remc.first] = aa;
        return aa;

    }
    int minCost(vector<int>& nums) {
        vector<vector<int>> arr(nums.size(), vector<int>(nums.size()));
        for(int i=0; i<nums.size(); i++) for(int j=0; j<nums.size(); j++) arr[i][j] = -1;
        if(nums.size() < 3)
        {
            int maxx =0;
            for(int i=0; i<nums.size(); i++) maxx = max(maxx, nums[i]);
            return maxx;
        }
        return what(nums, arr, {0,0}, 2);
    }
};