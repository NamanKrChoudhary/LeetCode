class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> arr(n+1);
        for(int i=0; i<conflictingPairs.size(); i++)
        {
            if(conflictingPairs[i][0]<conflictingPairs[i][1]) arr[conflictingPairs[i][0]].push_back(conflictingPairs[i][1]);
            else arr[conflictingPairs[i][1]].push_back(conflictingPairs[i][0]);
        }
        multiset<pair<int, int>> s;
        map<pair<int, int>, long long int> extra;
        long long int curr = 0;
        for(int i=n; i>0; i--)
        {
            for(int j=0; j<arr[i].size(); j++) s.insert({arr[i][j], i});
            if(s.empty())
            {
                curr = curr + (n-i+1);
                continue;
            }
            else
            {
                pair<int, int> fir = *s.begin();
                curr = curr + (fir.first - i);
                if(s.size() == 1)
                {
                    extra[fir] = extra[fir] + (n-fir.first+1);
                }
                else if(s.size() > 1)
                {
                    auto it = next(s.begin(), 1);
                    pair<int, int> sec = *it;
                    extra[fir] = extra[fir] + (sec.first-fir.first);
                }
            }
        }
        long long int maxx = 0;
        for(auto i: extra) maxx = max(maxx, i.second);
        cout << maxx << endl;
        return curr + maxx;
    }
};