class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        long long int n = nums.size();
        vector<long long int> prev(k, -1);
        vector<vector<long long int>> arr(nums.size(), vector<long long int>(k,1));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<k; j++)
            {
                if(prev[j] == -1) continue;
                arr[i][j] = arr[prev[j]][nums[i]%k]+1;
            }
            prev[nums[i]%k] = i;
        }
        long long int maxx = 1;
        for(int i=0; i<n; i++) for(int j=0; j<k; j++) maxx = max(maxx, arr[i][j]);
        return maxx;
    }
};