class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxx = 0;
        set<int> s;
        for(int i=0; i<nums.size(); i++)
        {
            if(s.count(nums[i])) continue;
            else if(nums[i] <= 0) continue;
            maxx = maxx + nums[i];
            s.insert(nums[i]);
        }
        return maxx;
    }
};