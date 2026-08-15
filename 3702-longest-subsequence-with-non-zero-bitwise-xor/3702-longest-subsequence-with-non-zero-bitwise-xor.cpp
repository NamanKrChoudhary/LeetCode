class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool check = false;
        long long int currxor = 0;
        long long int n = nums.size();
        for(int i=0; i<n; i++)
        {
            currxor = currxor ^ nums[i];
            if(nums[i] != 0) check = true;
        }
        if(check == false) return 0;
        if(currxor == 0) return n-1;
        else return n;
    }
};