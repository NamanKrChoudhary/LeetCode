class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long int> st(nums.size(), 0), end(nums.size(),0);
        for(int i=0; i<queries.size(); i++) {st[queries[i][0]]++; end[queries[i][1]]++;}
        bool check = true;
        long long int curr = 0;
        for(int i=0; i<nums.size(); i++)
        {
            curr = curr + st[i];
            if(curr < nums[i]){check = false; break;}
            curr = curr - end[i];
        }
        return check;
    }
};