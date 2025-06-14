class Solution {
public:
    int minMaxDifference(int num) {
        vector<long long int> maxx, minn;
        long long int temp = num;
        while(temp)
        {
            maxx.push_back(temp%10);
            minn.push_back(temp%10);
            temp = temp/10;
        }
        reverse(maxx.begin(), maxx.end());
        reverse(minn.begin(), minn.end());
        long long int maxc = -1, minc = -1;
        for(int i=0; i<maxx.size(); i++) if(maxx[i] != 9) {maxc = maxx[i]; maxx[i] = 9; break;}
        for(int i=0; i<minn.size(); i++) if(minn[i] != 0) {minc = minn[i]; minn[i] = 0; break;}
        if(maxc != -1) for(int i=0; i<maxx.size(); i++) if(maxx[i] == maxc) maxx[i] = 9;
        if(minc != -1) for(int i=0; i<minn.size(); i++) if(minn[i] == minc) minn[i] = 0;
        long long int fmax = 0, fmin=0;
        for(int i=0; i<maxx.size(); i++)
        {
            fmax = fmax*10; fmin = fmin*10;
            fmax = fmax + maxx[i]; fmin = fmin + minn[i];
        }
        return fmax-fmin;
    }
};