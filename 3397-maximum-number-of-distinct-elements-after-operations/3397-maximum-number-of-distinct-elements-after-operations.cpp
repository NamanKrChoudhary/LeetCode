class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        long long int n = nums.size();
        multiset<long long int> fin;
        vector<long long int> curr(n);
        for(int i=0; i<n; i++) curr[i] = nums[i];
        sort(curr.begin(), curr.end());
        long long int ptr = LLONG_MIN;
        for(long long int i=0; i<n; i++)
        {
            for(long long int j= max(curr[i]-k, ptr); j<= curr[i]+k; j++)
            {
                if(fin.find(j) == fin.end())
                {
                    fin.insert(j);
                    ptr = j+1;
                    break;
                }
            }
        }
        return fin.size();
    }
};