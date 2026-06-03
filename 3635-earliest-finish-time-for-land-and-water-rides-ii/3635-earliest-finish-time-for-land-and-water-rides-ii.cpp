class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // landfirst
        int minland = -1;
        for(int i=0; i<landStartTime.size(); i++)
        {
            int curr = landStartTime[i] + landDuration[i];
            if(minland == -1) minland = curr;
            minland = min(minland, curr);
        }
        int mintot = -1;
        int minwater = -1;
        for(int i=0; i<waterStartTime.size(); i++)
        {
            int curr = max(minland, waterStartTime[i]) + waterDuration[i];
            int curr1 = waterStartTime[i] + waterDuration[i];
            if(mintot == -1) mintot = curr;
            if(minwater == -1) minwater = curr1;
            mintot = min(mintot, curr);
            minwater = min(minwater, curr1);
        }
        //cout << minwater << endl;
        // waterfirst
        for(int i=0; i<landStartTime.size(); i++)
        {
            int curr = max(minwater, landStartTime[i]) + landDuration[i];
            mintot = min(mintot, curr);
        }
        return mintot;
    }
};