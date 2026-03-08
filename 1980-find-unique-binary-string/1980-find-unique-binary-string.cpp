class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        long long int n = nums.size();
        set<long long int> s;
        for(int i=0; i<n; i++)
        {
            long long int temp = 0;
            long long int currpow = 1;
            for(int j=nums[i].size()-1; j>=0; j--)
            {
                if(nums[i][j] == '1') temp = temp + currpow;
                currpow = currpow*2;
            }
            s.insert(temp);
        }
        long long int maxpow = 1;
        for(int i=0; i<n; i++) maxpow = maxpow*2;
        for(int i=0; i<maxpow; i++)
        {
            if(s.find(i) == s.end())
            {
                long long int temp = i;
                string curr = "";
                for(int i=0; i<n; i++)
                {
                    if(temp%2 == 1) curr.push_back('1');
                    else curr.push_back('0');
                    temp = temp/2;
                }
                reverse(curr.begin(), curr.end());
                return curr;
            }
        }
        return "00";
    }
};