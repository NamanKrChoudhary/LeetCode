class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long long int n = skill.size(), m = mana.size();
        vector<long long int> currend(n,0);
        long long int st = 0;
        long long int curr = 0;
        for(int j=0; j<m; j++)
        {
            long long int curradd = 0;
            curr = 0;
            for(int i=0; i<n; i++)
            {
                long long int prevend = curr + curradd;
                if(prevend < currend[i]) curr = currend[i]-curradd;
                curradd = curradd + (skill[i]*mana[j]); 
            }
            curradd = 0;
            for(int i=0; i<n; i++)
            {
                curradd = curradd + (skill[i]*mana[j]);
                currend[i] = curr + curradd;
            }
            st = currend[n-1];
        }
        return st;
    }
};