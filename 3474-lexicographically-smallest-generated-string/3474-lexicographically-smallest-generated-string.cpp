class Solution {
public:
    const long long int mod = 1e9+7;
    long long int modexp(long long int a, long long int b)
    {
        long long int res = 1;
        while(b)
        {
            if(b%2 == 1) res = (res*a)%mod;
            a = (a*a)%mod;
            b = b/2;
        }
        return res;
    }
    string generateString(string str1, string str2) {
        long long int n = str1.size(), m = str2.size();
        long long int base = 31;
        vector<long long int> pows(m), invpows(n);
        pows[0] = base;
        for(int i=1; i<m; i++) pows[i] = (pows[i-1]*base)%mod;
        invpows[m-1] = modexp(pows[m-1], mod-2);
        for(int i=m-2; i>=0; i--) invpows[i] = (invpows[i+1]*base)%mod;
        vector<long long int> hashval(n);
        hashval[0] = ((str2[0]-'a'+1)*pows[0])%mod;
        for(int i=1; i<m; i++) hashval[i] = (hashval[i-1]+ ((str2[i]-'a'+1)*pows[i])%mod)%mod;
        set<long long int> match;
        for(int i=1; i<m; i++)
        {
            long long int val1 = hashval[m-1-i];
            long long int val2 = (((hashval[m-1]-hashval[i]+mod)%mod)*invpows[i])%mod;
            if(val1 == val2) match.insert(i);
        }
        deque<long long int> active;
        vector<long long int> s(n+m-1);
        for(int i=0; i<n+m-1; i++)
        {
            while(!active.empty() && i-active.front()+1 > str2.size()) active.pop_front();
            if(i<n)
            {
                if(str1[i] == 'F')
                {
                    if(active.empty()) s[i] = -1;
                    else s[i] = i-active.front();
                }
                else
                {
                    for(int j=0; j<active.size(); j++)
                    {
                        if(match.find(i-active[j]) == match.end()) return "";
                    }
                    active.push_back(i);
                    s[i] = i-active.front();
                }
            }
            else
            {
                if(active.empty()) s[i] = -1;
                else s[i] = i-active.front();
            }
        }
        string temp = "";
        for(int i=0; i<m; i++) temp.push_back('a');
        string req(s.size(), '#');
        if(temp == str2)
        {
            temp[m-1] = 'b';
            for(int i=s.size()-2; i>=0; i--)
            {
                if(s[i+1] != -1 && s[i] == -1) req[i] = 'b';
            }
            long long int cnt = 0;
            for(int i=0; i<s.size(); i++)
            {
                if(s[i] == -1) 
                {
                    if(req[i] == '#') req[i] = temp[cnt%m]; cnt++;
                }
                else {req[i] = str2[s[i]]; cnt = 0;}
            }
        }
        else
        {
            for(int i=0; i<s.size(); i++)
            {
                if(s[i] == -1) req[i] = 'a';
                else req[i] = str2[s[i]];
            }
        }
        //for(int i=0; i<s.size(); i++) cout << s[i] << " "; cout << endl;
        return req;
    }
};