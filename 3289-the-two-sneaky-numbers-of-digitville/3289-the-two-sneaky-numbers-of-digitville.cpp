class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        long long int n = nums.size();
        vector<int> arr(n-2, 0);
        vector<int> sneaky;
        for(int i=0; i<n; i++) 
        {
            arr[nums[i]]++;
            if(arr[nums[i]] == 2) sneaky.push_back(nums[i]);
        }
        return sneaky;
    }
};