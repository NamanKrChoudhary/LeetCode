class Solution {
public:
    int maximumLength(vector<int>& nums) {
        bool check1 = true, check2 = false;
        int n = nums.size();
        vector<int> ee, eo, oe, oo;
        for(int i=0; i<n; i++)
        {
            if(nums[i]%2 == 0)
            {
                ee.push_back(nums[i]);
                if(check1 == true) {eo.push_back(nums[i]); check1 = false;}
                if(check2 == true) {oe.push_back(nums[i]); check2 = false;}
            }
            else
            {
                oo.push_back(nums[i]);
                if(check1 == false) {eo.push_back(nums[i]); check1 = true;}
                if(check2 == false) {oe.push_back(nums[i]); check2 = true;}
            }
        }
        int maxx = ee.size();
        maxx = max(maxx,(int) eo.size());
        maxx = max(maxx,(int) oe.size());
        maxx = max(maxx,(int) oo.size());
        return maxx;
    }
};