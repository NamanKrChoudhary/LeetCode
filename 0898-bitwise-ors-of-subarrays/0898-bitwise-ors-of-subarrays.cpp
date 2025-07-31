class Solution {
public:
    long long int modpow(long long int a, long long int b)
    {
        long long int res = 1;
        while(b)
        {
            if(b%2 == 1) res = res*a;
            a = a*a;
            b = b/2;
        }
        return res;
    }
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<vector<int>> arrbits(arr.size(), vector<int>(31));
        for(int i=0; i<arr.size(); i++)
        {
            long long int curr = arr[i];
            for(int j=0; j<31; j++)
            {
                arrbits[i][j] = curr%2;
                curr = curr/2;
            }
        }
        vector<int> currbits(31, -1);
        vector<map<int, vector<int>>> mp(arr.size());
        set<int> s;
        for(int i=arr.size()-1; i>=0; i--)
        {
            if(arr[i] == 0) {s.insert(0); continue;}
            for(int j=0; j<=30; j++) if(arrbits[i][j]) currbits[j] = i;
            for(int j=0; j<31; j++)
            {
                if(currbits[j] != -1) mp[i][currbits[j]].push_back(j);
            }
            long long int curr = 0;
            for(auto j: mp[i])
            {
                for(auto k: j.second) curr |= (1LL << k);
                s.insert(curr);
            }
            //s.insert(curr);
            //cout << i << endl;
        }
        //for(int i=0; i<arr.size(); i++) s.insert(arr[i]);
        //for(auto i: s) cout << i << " "; cout << endl;
        return s.size();
    }
};