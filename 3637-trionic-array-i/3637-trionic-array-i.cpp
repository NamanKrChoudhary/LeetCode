class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        long long int n = nums.size();
        long long int prev;
        if(nums[1] > nums[0]) prev = 1;
        else return false;
        vector<long long int> arr;
        arr.push_back(prev);
        for(int i=2; i<n; i++)
        {
            if(nums[i] == nums[i-1]) return false;
            if(nums[i] > nums[i-1] && prev == 2) {prev = 1; arr.push_back(prev);}
            else if(nums[i] < nums[i-1] && prev == 1) {prev = 2; arr.push_back(prev);}
        }
        if(arr.size() != 3) return false;
        else return true;
    }
};