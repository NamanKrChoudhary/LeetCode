
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long int n = nums.size()/3;
        long long int len = nums.size();
        priority_queue<long long int> pre;
        priority_queue<long long int, vector<long long int>, greater<long long int>> suf;
        for(int i=0; i<n; i++) pre.push(nums[i]);
        vector<long long int> mid1(n), mid2(n);
        long long int sum1 = 0, sum2 = 0;
        long long int sum = 0;
        for(int i=0; i<n; i++) {sum = sum + nums[i]; sum1 = sum1 + nums[i];}
        for(int i=0; i<n; i++) 
        {
            pre.push(nums[n+i]);
            long long int tt = pre.top();
            pre.pop();
            sum = sum + nums[n+i]-tt;
            mid1[i] = sum;
        }
        sum = 0;
        for(int i=0; i<n; i++)
        {
            suf.push(nums[len-1-i]);
            sum = sum + nums[len-1-i];
            sum2 = sum2 + nums[len-1-i];
        }
        for(int i=0; i<n; i++)
        {
            suf.push(nums[len-1-n-i]);
            long long int tt = suf.top();
            suf.pop();
            sum = sum + nums[len-1-n-i] - tt;
            mid2[n-1-i] = sum;
        }
        long long int maxx = min((sum1-mid2[0]), (mid1[n-1]-sum2));
        for(int i=1; i<n; i++)
        {
            maxx = min(maxx, (mid1[i-1]-mid2[i]));
        }
        return maxx;
    }
};