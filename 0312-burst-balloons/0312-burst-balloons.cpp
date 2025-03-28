class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr; arr.push_back(1);
        for(int i=0; i<nums.size(); i++) arr.push_back(nums[i]);
        arr.push_back(1); int n = arr.size();
        vector<vector<int>> v(n, vector<int> (n));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+2; j<n; j++)
            {
                long long int temp = 0;
                for(int k=i+1; k<j; k++)
                {
                    long long int curr = (arr[i]*arr[k]*arr[j]) + v[i][k] + v[k][j];
                    temp = max(temp, curr);
                }
                v[i][j] = temp;
            }
        }
        return v[0][n-1];
    }
};