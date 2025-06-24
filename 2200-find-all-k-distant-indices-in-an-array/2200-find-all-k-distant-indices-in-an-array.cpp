class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> arr;
        int n = nums.size();
        int last = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == key)
            {
                int st = max(last, i-k);
                int end = min(i+k, n-1);
                for(int j=st; j<=end && j<n; j++) arr.push_back(j);
                last = end+1;
            }
        }
        return arr;
    }
};