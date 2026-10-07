class Solution {
public:
    int minAddToMakeValid(string s) {
        long long int n = s.size();
        long long int req = 0;
        long long int curr = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(') curr = curr + 1;
            else if(s[i] == ')') curr = curr - 1;
            if(curr < 0) {req = req + 1; curr = 0;}
        }
        if(curr > 0) req = req + curr;
        return req;
    }
};