class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        long long int n = nums.size();
        sort(nums.begin(), nums.end());
        long long int minn = n-1;
        for(int i=0,j=0; i<n; i++)
        {
            if(j<i) j=i;
            long long int currel = nums[i];
            long long int currmax = currel*k;
            while(j<n-1 && nums[j+1] <= currmax) j = j+1;
            long long int curr = i+(n-j-1);
            minn = min(minn, curr);
        }
        return minn;
    }
};