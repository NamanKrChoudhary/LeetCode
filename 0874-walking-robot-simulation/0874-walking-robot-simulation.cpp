class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        long long int n = commands.size();
        long long int x=0,y=0;
        long long int dir = 0;
        map<pair<long long int, long long int>, bool> mp;
        for(int i=0; i<obstacles.size(); i++) mp[{obstacles[i][0], obstacles[i][1]}] = true;
        long long int maxx = 0;
        for(int i=0; i<n; i++)
        {
            if(commands[i] == -2) dir = (dir-1+4)%4;
            else if(commands[i] == -1) dir = (dir+1)%4;
            else
            {
                long long int xinc = 0, yinc = 0;
                if(dir == 0) yinc = 1;
                else if(dir == 1) xinc = 1;
                else if(dir == 2) yinc = -1;
                else if(dir == 3) xinc = -1;
                for(int j=0; j<commands[i]; j++)
                {
                    if(mp.find({x+xinc, y+yinc}) != mp.end()) break;
                    x = x+xinc;
                    y = y+yinc;
                    //cout << x << " " << y << " " << i << endl;
                    maxx = max(maxx, ((x*x)+(y*y)));
                }
            }
        }
        return maxx;
    }
};