class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        long long int n = nums.size();
        vector<pair<long long int, long long int>> temp(n);
        for(int i=0; i<n; i++) temp[i] = {nums[i], i};
        sort(temp.begin(), temp.end());
        long long int i = 0;
        vector<int> req(n);
        while(i<n)
        {
            vector<long long int> val, ind;
            val.push_back(temp[i].first);
            ind.push_back(temp[i].second);
            for(int j=i+1; j<n; j++)
            {
                if(temp[j].first-temp[j-1].first > limit) break;
                val.push_back(temp[j].first);
                ind.push_back(temp[j].second);
                i = j;
            }
            sort(val.begin(), val.end());
            sort(ind.begin(), ind.end());
            for(int j=0; j<val.size(); j++)
            {
                req[ind[j]] = val[j];
            }
            i = i+1;
        }
        return req;
    }
};