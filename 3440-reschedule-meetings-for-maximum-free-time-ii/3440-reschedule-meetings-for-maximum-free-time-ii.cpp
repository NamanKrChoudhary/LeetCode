class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        multiset<long long int> ms; 
        long long int n = startTime.size();
        if(startTime[0] != 0) ms.insert(startTime[0]);
        for(int i=1; i<n; i++) ms.insert(startTime[i]-endTime[i-1]);
        if(endTime[n-1] != eventTime) ms.insert(eventTime-endTime[n-1]);
        long long int maxx = 0;
        for(int i=0; i<n; i++)
        {
            long long int prevg=0, aftg=0;
            if(i==0) prevg = startTime[i];
            else prevg = startTime[i]-endTime[i-1];
            if(i==n-1) aftg = eventTime-endTime[i];
            else aftg = startTime[i+1]-endTime[i];
            long long int curr = endTime[i]-startTime[i];
            auto it = ms.find(prevg);
            if(it != ms.end()) ms.erase(it);
            it = ms.find(aftg);
            if(it != ms.end()) ms.erase(it);
            maxx = max(maxx, (aftg+prevg));
            it = ms.lower_bound(curr);
            if(it != ms.end()) 
            {
                maxx = max(maxx, (aftg+prevg+curr));
            }
            if(prevg!=0) ms.insert(prevg);
            if(aftg!=0) ms.insert(aftg);
        }
        return maxx;
    }
};