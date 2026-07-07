class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> nums;
        long long int temp = n;
        while(temp)
        {
            if(temp%10 > 0) nums.push_back(temp%10);
            temp = temp/10;
        }
        long long int x = 0;
        long long int sum = 0;
        for(int i=nums.size()-1; i>=0; i--)
        {
            x = (x*10)+nums[i];
            sum = sum + (nums[i]);
        }
        return x*sum;
    }
};