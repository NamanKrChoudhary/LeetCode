class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        vector<vector<int>> v(arr.size());
        for(int i=0; i<arr.size(); i++)
        {
            vector<int> curr;
            for(int j=0; j<i; j++)
            {
                if(arr[i]%arr[j] == 0 && curr.size() < v[j].size())
                {
                    curr = v[j];
                }
            }
            curr.push_back(arr[i]);
            v[i] = curr;
        }
        vector<int> ans;
        for(int i=0; i<arr.size(); i++) if(ans.size() < v[i].size()) ans = v[i];
        return ans;
    }
};