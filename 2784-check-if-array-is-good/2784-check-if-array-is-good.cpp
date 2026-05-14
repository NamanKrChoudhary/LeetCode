class Solution {
public:
    bool isGood(vector<int>& nums) {
        long long int n = nums.size();
        long long int xorr = 0;
        long long int cnt = 0;
        vector<int> arr(n,0);
        for(int i=0; i<n; i++)
        {
            if(nums[i] > n-1) return false;
            arr[nums[i]]++;
            // xorr = xorr^nums[i];
            // xorr = xorr^i;
        }
        //cout << xorr << endl;
        for(int i=1; i<n-1; i++) if(arr[i] != 1) return false;
        if(arr[n-1] != 2) return false;
        return true;

    }
};