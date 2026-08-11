class Solution {
public:
    int missingInteger(vector<int>& nums) {
        long long int n = nums.size();
        //long long int maxi = 0;
        long long int sum = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i]-nums[i-1] == 1) {sum = sum + nums[i];}
            else break;
        }
        // vector<long long int> missing(n);
        // missing[n-1] = nums[n-1] + 1;
        // for(int i=n-2; i>=0; i--)
        // {
        //     if(nums[i+1]-nums[i] == 1) missing[i] = missing[i+1];
        //     else missing[i] = nums[i]+1;
        // }
        long long int minn = 500; bool check = false;
        vector<bool> arr(n+1,false);
        for(int i=0; i<n; i++)
        {
            if(nums[i] >= sum && nums.size() >= nums[i]-sum) arr[nums[i]-sum] = true;
        }
        //cout << sum << endl;
        long long int curri = -1;
        for(int i=0; i<=n; i++) if(arr[i] == false) {curri = i+sum; break;}
        return curri;
    }
};