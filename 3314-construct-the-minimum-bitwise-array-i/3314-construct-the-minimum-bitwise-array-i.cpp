class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        long long int n = nums.size();
        vector<int> arr(n);
        for(int i=0; i<n; i++)
        {
            long long int temp = nums[i];
            vector<long long int> temparr(50);
            for(int i=0; i<50; i++) {temparr[i] = temp%2; temp = temp/2;}
            long long int lind = -1;
            for(int i=0; i<50; i++) 
            {
                if(temparr[i] == 1) lind = i;
                else break;
            }
            if(lind == -1) arr[i] = -1;
            else
            {
                arr[i] = nums[i] - pow(2, lind);
            }
        }
        return arr;
    }
};