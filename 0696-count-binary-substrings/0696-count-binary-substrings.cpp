class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<long long int> arr;
        char prev = s[0];
        long long int n = s.size();
        long long int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == prev) cnt = cnt + 1;
            else
            {
                arr.push_back(cnt);
                cnt = 1;
                prev = s[i];
            }
        }
        arr.push_back(cnt);
        long long int req = 0;
        for(int i=1; i<arr.size(); i++) req = req + min(arr[i], arr[i-1]);
        return req;
    }
};