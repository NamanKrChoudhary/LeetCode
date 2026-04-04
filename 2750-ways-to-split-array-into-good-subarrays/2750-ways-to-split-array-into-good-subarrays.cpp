class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long int n = nums.size();
        bool check = true;
        long long int cnt = 0;
        if(nums[0] == 0) check = false;
        vector<pair<long long int, long long int>> arr;
        for(int i=0; i<n; i++)
        {
            if(check == false && nums[i] == 0) cnt = cnt + 1;
            else if(check == false && nums[i] == 1)
            {
                arr.push_back({0, cnt});
                cnt = 1;
                check = true;
            }
            else if(check == true && nums[i] == 1) cnt = cnt + 1;
            else if(check == true && nums[i] == 0)
            {
                arr.push_back({1, cnt});
                cnt = 1;
                check = false;
            }
        }
        arr.push_back({check, cnt});
        long long int mod = 1e9+7;
        long long int req = 1;
        long long int z = 0;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i].first == 0) z = z + arr[i].second;
            if(i>0 && i<arr.size()-1 && arr[i].first == 0)
            {
                req = (req*(arr[i].second+1))%mod;
            }
        }
        if(z == n) return 0;
        return req;
    }
};