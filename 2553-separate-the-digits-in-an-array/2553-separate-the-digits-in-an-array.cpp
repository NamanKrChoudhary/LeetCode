class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        long long int n = nums.size();
        vector<int> req;
        for(int i=n-1; i>=0; i--) 
        {
            long long int temp = nums[i];
            while(temp > 0)
            {
                req.push_back(temp%10);
                temp = temp/10;
            }
        }
        reverse(req.begin(), req.end());
        return req;
    }
};