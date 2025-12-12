class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        long long int n = numberOfUsers;
        set<pair<long long int, long long int>> off;
        set<long long int> on;
        for(int i=0; i<n; i++) on.insert(i);
        vector<int> arr(n, 0);
        long long int all = 0;
        for(int i=0; i<events.size(); i++) 
        {
            swap(events[i][1], events[i][0]);
            if(events[i][1] == "MESSAGE") events[i][1] = "1";
            else events[i][1] = "0";
        }
        sort(events.begin(), events.end(), 
        [](const auto a, auto b)
        {
            if(a[0] != b[0]) return stoi(a[0]) < stoi(b[0]);
            return a[1] < b[1];
        });
        for(int i=0; i<events.size(); i++)
        {
            //cout << i << " " << events[i][0] << " " << events[i][1] << endl;
            long long int currtime = stoi(events[i][0]);
            while(!off.empty())
            {
                pair<long long int, long long int> temp = *off.begin();
                //cout << currtime << " " << temp.first << " " << temp.second << endl;
                if(temp.first <= currtime)
                {
                    off.erase(temp);
                    on.insert(temp.second);
                }
                else break;
            }
            if(events[i][1] == "0")
            {
                off.insert({currtime+60, stoi(events[i][2])});
                on.erase(stoi(events[i][2]));
            }
            else
            {
                if(events[i][2] == "ALL") all = all + 1;
                else if(events[i][2] == "HERE") 
                {
                    //cout << i << " " << on.size() << endl;
                    for(auto j: on) arr[j]++;
                }
                else
                {
                    string temp = "";
                    long long int c = 0;
                    for(int j=0; j<events[i][2].size(); j++)
                    {
                        if(c < 2) {c++; continue;}
                        else if(events[i][2][j] == ' ') 
                        {
                            long long int curr = stoi(temp);
                            arr[curr]++;
                            temp = "";
                            c = 0;
                        }
                        temp.push_back(events[i][2][j]);
                    }
                    long long int curr = stoi(temp);
                    arr[curr]++;
                }
            }
        }
        for(int i=0; i<n; i++) arr[i] = arr[i] + all;
        return arr;
    }
};