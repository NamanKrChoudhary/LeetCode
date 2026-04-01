class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        long long int n = positions.size();
        vector<vector<long long int>> line(n, vector<long long int>(4));
        for(int i=0; i<n; i++)
        {
            line[i][0] = positions[i];
            if(directions[i] == 'L') line[i][1] = 0;
            else line[i][1] = 1;
            line[i][2] = healths[i];
            line[i][3] = i;
        }
        sort(line.begin(), line.end());
        vector<pair<long long int, long long int>> live;
        stack<pair<long long int, long long int>> s;
        for(int i=0; i<n; i++)
        {
            if(line[i][1] == 0)
            {
                long long int temp = line[i][2];
                while(!s.empty() && temp > 0)
                {
                    pair<long long int, long long int> curr = s.top();
                    s.pop();
                    if(curr.first > temp)
                    {
                        curr.first = curr.first - 1;
                        temp = 0;
                        s.push(curr);
                    } 
                    else if(curr.first < temp)
                    {
                        temp = temp - 1;
                    }
                    else temp = 0;
                }
                if(temp > 0) live.push_back({line[i][3], temp});
            }
            else
            {
                s.push({line[i][2],line[i][3]});
            }
        }
        while(!s.empty())
        {
            pair<long long int, long long int> curr = s.top();
            s.pop();
            live.push_back({curr.second, curr.first});
        }
        sort(live.begin(), live.end());
        vector<int> req;
        for(int i=0; i<live.size(); i++) req.push_back(live[i].second);
        return req;
        //15r 10r 10l 12l

    }
};