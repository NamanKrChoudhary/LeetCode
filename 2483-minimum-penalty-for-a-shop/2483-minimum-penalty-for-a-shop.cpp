class Solution {
public:
    int bestClosingTime(string customers) {
        long long int n = customers.size();
        vector<long long int> pref(n);
        long long int y = 0;
        for(int i=0; i<n; i++)
        {
            pref[i] = y;
            if(customers[i] == 'Y') y = y + 1;
        }
        long long int minnind = 0, minn = n;
        for(int i=0; i<n; i++)
        {
            long long int currpen = (i-pref[i]) + (y-pref[i]);
            //cout << currpen << endl;
            if(currpen < minn)
            {
                minn = currpen;
                minnind = i;
            }
        }
        if(n-y < minn) return n;
        return minnind;
    }
};