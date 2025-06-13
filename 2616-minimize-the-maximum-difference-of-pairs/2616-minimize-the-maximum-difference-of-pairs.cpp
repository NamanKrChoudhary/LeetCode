class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        long long int pr = 1e9;
        long long int st = 0, end = arr[nums.size()-1], mid = st + (end-st)/2;
        while(st <= end)
        {
            mid = st + (end-st)/2;
            long long int temp = 0;
            for(int i=1; i<arr.size();)
            {
                if(arr[i]-arr[i-1] <= mid) {temp = temp + 1; i = i+2;}
                else i = i+1;
            }
            if(temp >= p) {pr = min(mid, pr); end = mid-1;}
            else st = mid + 1;
        }
        return pr;
    }
};