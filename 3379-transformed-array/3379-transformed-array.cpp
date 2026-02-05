class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        long long int n = nums.size();
        vector<int> req(n);
        for(int i=0; i<n; i++)
        {
            long long int ind = i;
            if(nums[i] > 0) 
            {
                ind = (i + nums[i])%n;
            }
            else if(nums[i] < 0)
            {
                ind = (((i+nums[i])%n) + n)%n;
            }
            //cout << ind << " ";
            req[i] = nums[ind];
        }
        return req;
    }
};