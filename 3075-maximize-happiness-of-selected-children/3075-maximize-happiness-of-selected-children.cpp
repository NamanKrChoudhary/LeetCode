class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long int n = happiness.size();
        vector<int> arr = happiness;
        sort(happiness.rbegin(), happiness.rend());
        long long int cnt = 0, currcnt = 0;
        long long int req = 0;
        for(int i=0; i<min(n, static_cast<long long int>(k)); i++)
        {
            req = req + max(static_cast<long long int>(happiness[i]-currcnt), 0LL);
            currcnt = currcnt + 1;
        }
        return req;
    }
};