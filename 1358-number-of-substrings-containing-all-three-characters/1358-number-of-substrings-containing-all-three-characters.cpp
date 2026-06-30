class Solution {
public:
    int numberOfSubstrings(string s) {
        long long int n = s.size();
        vector<int> a(n,0), b(n,0), c(n,0);
        // if(s[0] == 'a') a[0] = 1;
        // else if(s[0] == 'b') b[0] = 1;
        // else c[0] = 1;
        for(int i=1; i<n; i++)
        {
            a[i] = a[i-1];
            b[i] = b[i-1];
            c[i] = c[i-1];
            if(s[i] == 'a') a[i] = a[i] + 1;
            else if(s[i] == 'b') b[i] = b[i] + 1;
            else if(s[i] == 'c') c[i] = c[i] + 1;
        }
        long long int req = 0;
        for(int i=0; i<n; i++)
        {
            long long int curra = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
            long long int currb = upper_bound(b.begin(), b.end(), b[i]) - b.begin();
            long long int currc = upper_bound(c.begin(), c.end(), c[i]) - c.begin();
            //cout << curra << " " << currb << " " << currc << endl;
            long long int maxx = 0;
            if(s[i] == 'a') maxx = max(currb, currc);
            else if(s[i] == 'b') maxx = max(curra, currc);
            else maxx = max(curra, currb);
            req = req + (n-maxx);
        }
        return req;
    }
};