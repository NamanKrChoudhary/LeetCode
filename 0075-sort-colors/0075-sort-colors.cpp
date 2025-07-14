class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                int j = i;
                while(j > 0) {swap(nums[j], nums[j-1]); j--;}
            }
            else if(nums[i] == 2)
            {
                int j = i;
                while(j<nums.size()-1) {swap(nums[j+1], nums[j]); j++;}
                if(nums[i] == 0)
                {
                    j = i;
                    while(j>0) {swap(nums[j], nums[j-1]); j--;}
                }
            }
        }
        return;
    }
};