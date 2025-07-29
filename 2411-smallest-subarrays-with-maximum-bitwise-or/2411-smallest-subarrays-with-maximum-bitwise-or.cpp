class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<long long int> req(nums.size());
        long long int curror = 0;
        for(int i=nums.size()-1; i>=0; i--)
        {
            curror = curror|nums[i];
            req[i] = curror;
        }
        vector<vector<int>> reqbits(nums.size(), vector<int>(31));
        for(int i=0; i<nums.size(); i++)
        {
            long long int curr = req[i];
            for(int j=0; j<=30; j++)
            {
                reqbits[i][j] = curr%2;
                curr = curr/2;
            }
        }
        vector<vector<int>> numsbits(nums.size(), vector<int>(31));
        for(int i=0;i <nums.size(); i++)
        {
            long long int curr = nums[i];
            for(int j=0; j<=30; j++)
            {
                numsbits[i][j] = curr%2;
                curr = curr/2;
            }
        }
        vector<int> curr(31, 0);
        vector<int> len(nums.size());
        for(int i=0, j=0; i<nums.size() && j<=nums.size();)
        {
            bool check = true;
            for(int k=0; k<=30; k++)
            {
                if(reqbits[i][k] > 0 && curr[k] <= 0) {check = false; break;}
            }
            if(check == false) 
            {
                for(int k=0; k<=30; k++) curr[k] = curr[k] + numsbits[j][k];
                j++;
                continue;
            }
            else
            {
                len[i] = j-i;
                for(int k=0; k<=30; k++) curr[k] = curr[k] - numsbits[i][k];
                if(j == i) {len[i] = 1; i++; j++;}
                else i++;
            }
        }
        return len;
    }
};