class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        deque<pair<long long int, long long int>> arr;
        long long int n = nums.size();
        long long int todel = 0;
        for(int i=0; i<n; i++)
        {
            if(todel > nums[i]) return false;
            if(todel < nums[i] && i> n-k) return false;
            if(todel < nums[i] && i <= n-k) arr.push_back({nums[i]-todel, i+k-1});
            todel = nums[i];
            if(!arr.empty() && arr[0].second == i) 
            {
                todel = todel - arr[0].first;
                arr.pop_front();
            }
        }
        return true;
    }
};