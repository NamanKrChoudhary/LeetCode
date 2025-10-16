class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<long long int, long long int> mp;
        for(int i=0; i<nums.size(); i++) 
        {
            if(nums[i]<0)
            {
                long long int mul = abs(nums[i]/value);
                if(abs(nums[i])%value != 0) mul = mul + 1;
                mp[(nums[i]+(value*mul))%value]++;
            }
            else mp[nums[i]%value]++;
        }
        long long int req = 0;
        while(true)
        {
            if(mp.find(req%value) != mp.end() && mp[req%value] > 0)
            {
                mp[req%value]--;
                req = req+1;
            }
            else return req;
        }
    }
};