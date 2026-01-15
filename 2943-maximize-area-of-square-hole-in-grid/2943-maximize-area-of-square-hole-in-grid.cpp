class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        long long int maxxi = 0;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        for(int i=0, j=0; i<hBars.size(); i++)
        {
            if(j<i) j = i;
            while(j<hBars.size()-1 && hBars[j+1]-hBars[j] == 1) j = j+1;
            maxxi = max(maxxi, static_cast<long long int>(j-i+2));
        }
        long long int maxxj = 0;
        for(int i=0, j=0; i<vBars.size(); i++)
        {
            if(j<i) j = i;
            while(j<vBars.size()-1 && vBars[j+1]-vBars[j] == 1) j = j+1;
            maxxj = max(maxxj, static_cast<long long int>(j-i+2));
        }
        return min(maxxi, maxxj)*min(maxxi, maxxj);
    }
};