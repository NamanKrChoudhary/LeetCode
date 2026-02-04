class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long int maxx = LLONG_MIN;
        long long int n = nums.size();
        for(int i=0,j=0; i<n; i++)
        {
            j = i;
            while(j<n-1 && nums[j] > nums[j+1]) j = j+1;
            if(i<j && i>0 && nums[i-1] < nums[i] && j<n-1 && nums[j] < nums[j+1])
            {
                long long int curr = nums[i];
                for(int k=i+1; k<=j; k++) curr = curr + nums[k];
                long long int nextj = j+1;
                long long int nextmax = nums[j+1];
                long long int nextsum = nums[j+1];
                while(nextj<n-1 && nums[nextj] < nums[nextj+1])
                {
                    nextj = nextj + 1;
                    nextsum = nextsum + nums[nextj];
                    nextmax = max(nextmax, nextsum);
                }
                long long int prevj = i-1;
                long long int prevmax = nums[prevj];
                long long int prevsum = nums[prevj];
                while(prevj>0 && nums[prevj] > nums[prevj-1])
                {
                    prevj = prevj-1;
                    prevsum = prevsum + nums[prevj];
                    prevmax = max(prevmax, prevsum);
                }
                curr = curr + nextmax + prevmax;
                maxx = max(maxx, curr);
            }
            i = j;
        }
        return maxx;
    }
};