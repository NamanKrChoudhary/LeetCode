class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<long long int> gap;
        if(startTime[0] != 0) gap.push_back(startTime[0]);
        long long int prev = endTime[0];
        for(int i=1; i<startTime.size(); i++) {gap.push_back(startTime[i]-prev); prev = endTime[i];}
        if(prev != eventTime) gap.push_back(eventTime-prev);
        if(gap.size() <= k+1)
        {
            long long int curr = 0;
            for(int i=0; i<gap.size(); i++) curr = curr + gap[i];
            return curr;
        }
        else
        {
            long long int curr = 0;
            for(int i=0; i<k+1; i++) curr = curr + gap[i];
            long long int maxx = curr;
            for(int i=0, j=k+1; j<gap.size(); i++, j++)
            {
                curr = curr-gap[i];
                curr = curr+ gap[j];
                maxx = max(maxx, curr);
            }
            return maxx;
        }
    }
};