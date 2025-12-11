class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<long long int, vector<long long int>> horizontal;
        map<long long int, vector<long long int>> vertical;
        for(int i=0; i<buildings.size(); i++)
        {
            horizontal[buildings[i][1]].push_back(buildings[i][0]);
            vertical[buildings[i][0]].push_back(buildings[i][1]);
        }
        map<pair<long long int, long long int>, long long int> mp;
        for(auto i: horizontal)
        {
            vector<long long int> temp = i.second;
            sort(temp.begin(), temp.end());
            for(int j=1; j<temp.size()-1; j++) mp[{temp[j], i.first}]++;
        }
        for(auto i: vertical)
        {
            vector<long long int> temp = i.second;
            sort(temp.begin(), temp.end());
            for(int j=1; j<temp.size()-1; j++) mp[{i.first, temp[j]}]++;
        }
        long long int cnt = 0;
        for(auto i: mp) if(i.second > 1) cnt = cnt + 1;
        return cnt;
    }
};