class Solution {
public:
    long long int modpow(long long int a, long long int b)
    {
        long long int res = 1;
        while(b)
        {
            if(b&1) res = res*a;
            a = (a*a);
            b = b/2;
        }
        return res;
    }

    int longestSubsequence(string s, int k) {
        string a = s;
        reverse(a.begin(), a.end());
        long long int curr = 0;
        long long int cnt = 0;
        long long int temp = k;
        long long int maxx = 0;
        while(temp) {maxx = maxx + 1; temp = temp/2;}
        for(int i=0; i<a.size(); i++)
        {
            if(a[i] == '0') {cnt = cnt + 1; continue;}
            else
            {
                if(cnt > maxx) continue;
                else
                {
                    if(curr+modpow(2, cnt) <= k)
                    {
                        curr = curr + modpow(2, cnt);
                        cnt = cnt + 1;
                    }
                    else continue;
                }
            }
        }
        return cnt;
    }
};