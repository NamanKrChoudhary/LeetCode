class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<long long int>> arr(events.size(), vector<long long int>(k+1));
        vector<long long int> st, end;
        vector<pair<long long int, long long int>> prs;
        for(int i=0; i<events.size(); i++)
        {
            st.push_back(events[i][0]);
            end.push_back(events[i][1]);
            prs.push_back({events[i][0],i});
        }
        sort(st.begin(), st.end());
        sort(prs.begin(), prs.end());
        for(int i=st.size()-1; i>=0; i--)
        {
            for(int j=1; j<=k; j++)
            {
                long long int curr1 = 0;
                long long int curr2 = 0;
                if(j == 1) curr2 = events[prs[i].second][2];
                long long int it1 = upper_bound(st.begin(), st.end(), st[i]) - st.begin();
                long long int it2 = upper_bound(st.begin(), st.end(), events[prs[i].second][1]) - st.begin();
                if(it1 < st.size()) curr1 = curr1 + arr[it1][j];
                if(it2 < st.size()) curr2 = events[prs[i].second][2] + arr[it2][j-1];
                arr[i][j] = max(curr1, curr2);
            }
        }
        long long int maxx = 0;
        for(int i=0; i<arr.size(); i++) for(int j=0; j<arr[i].size(); j++) maxx = max(maxx, arr[i][j]);
        return maxx;
    }
};