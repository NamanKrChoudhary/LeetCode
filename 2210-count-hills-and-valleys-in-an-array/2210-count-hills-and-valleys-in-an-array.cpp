class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<pair<long long int,long long int>> arr;
        long long int prev = nums[0];
        long long int cnt = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == prev) cnt = cnt + 1;
            else
            {
                arr.push_back({prev, cnt});
                prev = nums[i];
                cnt = 1;
            }
        }
        arr.push_back({prev, cnt});
        cnt = 0;
        for(int i=2; i<arr.size(); i++)
        {
            if(arr[i-1].first > arr[i].first && arr[i-1].first > arr[i-2].first) cnt = cnt + 1;
            if(arr[i-1].first < arr[i].first && arr[i-1].first < arr[i-2].first) cnt = cnt + 1;
        }
        return cnt;
    }
};