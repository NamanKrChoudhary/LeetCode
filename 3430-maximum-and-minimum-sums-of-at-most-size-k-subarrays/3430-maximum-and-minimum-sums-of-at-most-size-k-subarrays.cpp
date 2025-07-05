class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        deque<long long int> d;
        long long int n = nums.size();
        vector<long long int> left(n), right(n);
        for(int i=0; i<n; i++) 
        {
            while(!d.empty() && d.front() <= i-k) d.pop_front();
            while(!d.empty() && nums[d.back()] > nums[i]) d.pop_back();
            if(d.empty()) left[i] = min(k, i+1);
            else left[i] = i-d.back();
            d.push_back(i);
        }
        d.clear();
        for(int i=0; i<n; i++) 
        {
            while(!d.empty() && d.front() <= i-k) d.pop_front();
            while(!d.empty() && nums[n-1-d.back()] >= nums[n-1-i]) d.pop_back();
            if(d.empty()) right[n-1-i] = min(k, i+1);
            else right[n-1-i] = i-d.back();
            d.push_back(i);
        }
        d.clear();
        vector<long long int> lg(n), rg(n);
        for(int i=0; i<n; i++) 
        {
            while(!d.empty() && d.front() <= i-k) d.pop_front();
            while(!d.empty() && nums[d.back()] < nums[i]) d.pop_back();
            if(d.empty()) lg[i] = min(k, i+1);
            else lg[i] = i-d.back();
            d.push_back(i);
        }
        d.clear();
        for(int i=0; i<n; i++) 
        {
            while(!d.empty() && d.front() <= i-k) d.pop_front();
            while(!d.empty() && nums[n-1-d.back()] <= nums[n-1-i]) d.pop_back();
            if(d.empty()) rg[n-1-i] = min(k, i+1);
            else rg[n-1-i] = i-d.back();
            d.push_back(i);
        }
        long long int run = 0;
        for(int i=0; i<n; i++)
        {
            if(left[i]+right[i]-1 <= k) {run = run + (nums[i]*(right[i]*left[i]));}
            else {
            for(int j=0; j<left[i]; j++)
            {
                long long int curr = k-j;
                run = run + (nums[i]*min(curr, (right[i])));
            }
            }
            if(lg[i]+rg[i]-1 <= k) {run = run + (nums[i]*(rg[i]*lg[i]));}
            else {
            for(int j=0; j<lg[i]; j++) 
            {
                long long int curr = k-j;
                run = run + (nums[i]*min(curr, (rg[i])));
            }
            }
        }
        return run;
    }
};