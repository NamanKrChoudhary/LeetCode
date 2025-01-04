class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        deque<long long int> arr;
        long long int ans = 0;
        long long int n = nums.size();
        for(int i=0; i<n; i++)
        {
            while(!arr.empty() && arr[0]<i) arr.pop_front();
            if(arr.empty() || arr.size()%2 == 0)
            {
                if(nums[i] == 0)
                {
                    if(i > (n-k) && i<n) {ans = -1; break;}
                    ans = ans + 1;
                    arr.push_back(i+k-1);
                }
            }
            else if(arr.size()%2 == 1)
            {
                if(nums[i] == 1)
                {
                    if(i > (n-k) && i<n) {ans = -1; break;}
                    ans = ans + 1;
                    arr.push_back(i+k-1);
                }
            }
        }
        return ans;
    }
};