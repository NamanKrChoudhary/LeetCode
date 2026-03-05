class Solution {
public:
    int minOperations(string s) {
        long long int req1 = 0, req2 = 0;
        long long int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(i%2 == 0)
            {
                if(s[i] == '1') req1 = req1 + 1;
                else req2 = req2 + 1;
            }
            else
            {
                if(s[i] == '0') req1 = req1 + 1;
                else req2 = req2 + 1;
            }
        }
        return min(req1, req2);
    }
};