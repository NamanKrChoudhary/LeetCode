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
    long long int validind(string& s, vector<long long int>& way, long long int k)
    {
        string first;
        for(int i=0; i<s.size()/2; i++) first.push_back(s[i]);
        sort(first.begin(), first.end());
        map<char, long double> cnt;
        long double ways = 1;
        for(int i=first.size()-1, j = 1; i>=0; i--, j++)
        {
            ways = ways*j;
            cnt[first[i]]++;
            ways = ways/cnt[first[i]];
            way[i] = ways;
            //cout << i << " " << ways << endl;
            if(ways >= k) return i;
        }
        return -1;
    }
    string smallestPalindrome(string s, int k) {
        vector<long long int> way(s.size()/2, -1);
        long long int ind = validind(s, way, k);
        long long int n = s.size()/2;
        string req = "";
        if(k == 1)
        {
            for(int i=0; i<s.size()/2; i++) req.push_back(s[i]);
            sort(req.begin(), req.end());
            if(s.size()%2 == 1) req.push_back(s[s.size()/2]);
            for(int i=s.size()/2-1; i>=0; i--) req.push_back(req[i]);
            return req;
        }
        if(ind == -1) return req;
        //vector<char> ss;
        multiset<char> ms;
        map<char, long long int> mp;
        for(long long int i=0; i<n; i++) {ms.insert(s[i]); mp[s[i]]++;}
        deque<char> chars1; deque<long long int> cnt1;
        for(auto i: mp) if(i.second > 0 && i.first-'a' >= 0 && i.first-'a' < 26) {chars1.push_back(i.first); cnt1.push_back(i.second);}

        for(int i=0; i<ind; i++)
        {
            if(cnt1[0] == 0) {chars1.pop_front(); cnt1.pop_front();}
            req.push_back(chars1[0]);
            cnt1[0]--;
            mp[chars1[0]]--;
        }
        //for(auto i: mp) cout << i.first << " " << i.second << endl;
        
        vector<char> chars; vector<long long int> cnt;
        //for(int i=0; i<chars1.size(); i++) if(cnt1[i] > 0) {chars.push_back(chars1[i]); cnt.push_back(cnt1[i]);}
        for(auto i: mp) if(i.second > 0) {cnt.push_back(i.second); chars.push_back(i.first);}
        //for(int i=0; i<chars.size(); i++) cout << chars1[i] << " " << cnt1[i] << endl;
        long double totways = way[ind];
        long double curr = 0;
        //cout << req << endl;
        //cout << ind << endl;
        for(int i=ind; i<s.size()/2; i++)
        {
            long double toadd = 0;
            long long int charind = 0;
            while(curr + toadd < k)
            {
                //if(charind >= s.size()/2) return req
                curr = curr + toadd; 
                toadd = totways*cnt[charind];
                toadd = toadd/(s.size()/2 - i);
                charind = charind + 1;
            }
            charind = charind-1;
            //cout << i << " " << charind << " " << chars[charind] << endl;
            req.push_back(chars[charind]);
            totways = totways*cnt[charind];
            totways = totways/(s.size()/2 - i);
            cnt[charind]--;
            if(cnt[charind] == 0)
            {
                cnt.erase(cnt.begin()+charind);
                chars.erase(chars.begin()+charind);
            }
        }
        if(s.size()%2 == 1) req.push_back(s[s.size()/2]);
        for(int i=s.size()/2-1; i>=0; i--) req.push_back(req[i]);
        return req;
    }
};