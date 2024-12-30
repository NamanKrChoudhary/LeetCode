class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        long long int s = 0, e = 1e6, mid = s+ ((e-s)/2);
        long long int ans = 0;
        while(s<=e)
        {
            mid = s + ((e-s)/2);
            long long int total = 0;
            for(int i=0,j=0; i<nums.size() && j<nums.size(); i++)
            {
                while(j<=i && (abs(arr[i]-arr[j]) > mid)) j++;
                total = total +max(0, (i-j));
            }
            if(total < k) s = mid + 1;
            else {ans = mid; e = mid-1;}
        }
        return ans;
    }
};