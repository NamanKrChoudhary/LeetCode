class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long int n = nums.size();
        deque<long long int> arr(n);
        long long int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum = sum + nums[i];
            arr[i] = sum;
        }
        vector<int> ans(n);
        if(k == 0)
        {
            for(int i=0; i<n; i++) ans[i] = nums[i];
            return ans;
        }
        for(int i=0; i<n; i++)
        {
            if(i-k <0 || i+k >=n) {ans[i] = -1; continue;}
            ans[i] = (arr[i+k]-arr[i-k]+nums[i-k])/((2*k)+1);
            cout << arr[i+k] << " " << arr[i-k] << " "<< nums[i-k] << endl;
        }
        return ans;
    }
};