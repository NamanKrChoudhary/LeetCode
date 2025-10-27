class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long int n = bank.size();
        long long int LaserBeam = 0;
        long long int prev = 0;
        for(int i=0; i<n; i++)
        {
            long long int curr = 0;
            for(int j=0; j<bank[i].size(); j++) if(bank[i][j] == '1') curr = curr + 1;
            if(curr > 0) 
            {
                LaserBeam = LaserBeam + (curr*prev);
                prev = curr;
            }
        }
        return LaserBeam;
    }
};