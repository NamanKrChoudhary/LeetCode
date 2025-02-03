class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long int total = 0;
        for(int i=0; i<nums.size(); i++) total = total+nums[i];
        if(total%2 == 1 || nums.size() == 1) return false;
        vector<vector<long long int>> arr(nums.size(), vector<long long int>((total/2) + 1));
        arr[0][nums[0]] = true;
        for(int i=1; i<nums.size(); i++)
        {
            for(int j=0; j<=total/2; j++)
            {
                bool check1 = arr[i-1][j];
                bool check2 = false;
                if(j-nums[i] >= 0) check2 = arr[i-1][j-nums[i]];
                arr[i][j] = check1 || check2;
            }
        }
        return arr[nums.size()-1][(total/2)];
    }
};