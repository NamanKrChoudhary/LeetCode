class Solution {
public:
    int minElement(vector<int>& nums) {
        int minn = 1e5;
        for(int i=0; i<nums.size(); i++)
        {
            int temp = nums[i];
            int curr = 0;
            while(temp)
            {
                curr = curr + (temp%10);
                temp = temp/10;
            }
            minn = min(minn, curr);
        }
        return minn;
    }
};