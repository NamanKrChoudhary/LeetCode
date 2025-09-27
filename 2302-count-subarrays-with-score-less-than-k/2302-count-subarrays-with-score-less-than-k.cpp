class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int sum = 0, i = 0, j = -1;
        long long int count = 0;
        //cout << i << " " << j << endl;
        long long int n = nums.size();
        while(i<n && j<n)
        {
            //cout << i << " " << j << " " << sum << endl;
            while(j<n-1 && (sum+nums[j+1])*(j-i+2) < k)
            {
                sum = sum + nums[j+1];
                j = j+1;
            }
            count = count + (j-i+1);
            sum = sum - nums[i];
            i = i + 1;
        }
        return count;
    }
};