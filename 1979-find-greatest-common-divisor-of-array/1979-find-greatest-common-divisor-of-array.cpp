class Solution {
public:
    int findGCD(vector<int>& nums) {
        long long int maxx = 0, minn = 1e15;
        for(int i=0; i<nums.size(); i++) 
        {
            if(maxx < nums[i]) maxx = nums[i];
            if(minn > nums[i]) minn = nums[i];
        }
        return __gcd(maxx, minn);
    }
};