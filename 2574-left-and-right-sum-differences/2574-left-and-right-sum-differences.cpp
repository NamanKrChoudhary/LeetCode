class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        long long int total = 0;
        for(int i=0; i<nums.size(); i++) total = total + nums[i];
        long long int prev = 0;
        vector<int> req;
        for(int i=0; i<nums.size(); i++)
        {
            total = total - nums[i];
            req.push_back(abs(prev-total));
            prev = prev + nums[i];
        }
        return req;
    }
};