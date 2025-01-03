class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> arr;
        for(int i=0; i<nums.size(); i++)
        {
            if(i>=k && !d.empty())
            {
                if(d[0] == nums[i-k]) d.pop_front();
            }
            while(!d.empty() && d[d.size()-1] < nums[i])
            {
                d.pop_back();
            }
            d.push_back(nums[i]);
            if(i >= k-1) arr.push_back(d[0]);
        }
        for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
        return arr;
    }
};