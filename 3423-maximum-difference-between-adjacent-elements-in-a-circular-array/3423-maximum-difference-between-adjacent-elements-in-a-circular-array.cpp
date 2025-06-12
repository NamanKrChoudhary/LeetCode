class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        vector< int> arr = nums;
        arr.push_back(nums[0]);
        int maxx = 0;
        for(int i=1; i<arr.size(); i++) maxx = max(maxx, abs(arr[i]-arr[i-1]));
        return maxx;
    }
};