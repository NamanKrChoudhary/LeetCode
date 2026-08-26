class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        long long int low = lower, up = upper;
        vector<long long int> arr;
        for(int i=0; i<nums.size(); i++) arr.push_back(nums[i]);
        arr.push_back(upper+1); arr.push_back(lower-1);
        sort(arr.begin(), arr.end());
        vector<vector<int>> req;
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i]-arr[i-1] > 1)
            {
                long long int left = max(arr[i-1]+1, low);
                long long int right = min(arr[i]-1, up);
                if(left <= right)
                {
                    int a = left, b = right;
                    req.push_back({a,b});
                }
            }
        }
        return req;
    }
};