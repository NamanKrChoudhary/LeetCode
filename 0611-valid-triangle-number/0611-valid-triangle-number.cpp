class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        long long int cnt = 0;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size()-1; j++)
            {
                if(i == j) continue;
                long long int diff = abs(arr[i]-arr[j]);
                long long int sum = arr[i]+arr[j];
                long long int e = lower_bound(arr.begin()+j+1, arr.end(), sum) - arr.begin();
                long long int s = upper_bound(arr.begin()+j+1, arr.end(), diff) - arr.begin();
                long long int currcnt = e-s;
                //cout << i << " " << j << " " << e << " " << s << endl;
                if(currcnt > 0)cnt = cnt + currcnt;
            }
        }
        return cnt;
    }
};