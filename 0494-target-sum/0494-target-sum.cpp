class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> s;
        s.insert(0);
        for(int i=0; i<nums.size(); i++)
        {
            vector<int> temp;
            for(auto it: s)
            {
                temp.insert(it-nums[i]);
            }
            for(auto it: s) temp.insert(it+nums[i]);
            s = temp;
        }
        int count = 0;
        for(auto i: s) if(i == target) count = count + 1;
        return count;
    }
};