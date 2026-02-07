class Solution {
public:
    int minimumDeletions(string s) {
        long long int n = s.size();
        long long int minn = n-1;
        long long int tota = 0, totb = 0;
        for(int i=0; i<n; i++) 
        {
            if(s[i] == 'a') tota = tota + 1;
            else totb = totb + 1;
        }
        long long int curra = 0, currb = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'a') 
            {
                curra = curra + 1;
                long long int currdel = currb + (tota-curra);
                minn = min(minn, currdel);
            }
            else 
            {
                long long int currdel = currb + (tota-curra);
                minn = min(minn, currdel);
                currb = currb + 1;
            }

        }
        return minn;
    }
};