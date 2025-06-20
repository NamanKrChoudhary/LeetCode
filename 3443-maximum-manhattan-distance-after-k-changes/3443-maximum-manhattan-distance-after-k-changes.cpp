class Solution {
public:
    int maxDistance(string s, int k) {
        long long int n = s.size();
        vector<pair<long long int, long long int>> ver(s.size()), hor(s.size());
        long long int posv = 0, negv = 0, posh = 0, negh = 0;
        long long int maxx = 0;
        long long int currk = k;
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'N') posv = posv+1;
            else if(s[i] == 'S') negv = negv+1;
            else if(s[i] == 'W') negh = negh + 1;
            else if(s[i] == 'E') posh = posh + 1;
            long long int chv = min(min(posv, negv), currk);
            long long int currv = (max(posv, negv) + chv) - (min(posv, negv) - chv);
            long long int remch = k-chv;
            long long int chh = min(min(posh, negh), remch);
            long long int currh = (max(posh, negh) + chh) - (min(posh, negh) - chh);
            maxx = max(maxx, currh+currv);
        }
        return maxx;
    }
};