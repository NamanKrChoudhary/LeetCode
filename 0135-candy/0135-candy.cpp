class Solution {
public:
    int candy(vector<int>& ratings) {
        long long int n = ratings.size();
        if(n == 0) return 0;
        else if(n == 1) return 1;
        else if(n == 2 && ratings[0] == ratings[1]) return 2;
        else if(n == 2) return 3;
        vector<long long int> curr(n);
        curr[0] = 1;
        for(int i=1; i<n; i++)
        {
            if(ratings[i] > ratings[i-1]) curr[i] = curr[i-1]+1;
            else curr[i] = 1;
        }
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1]) curr[i] = max(curr[i+1]+1, curr[i]);
            else curr[i] = max(int(curr[i]),1);
        }
        long long int ans = 0;
        for(int i=0; i<n; i++) ans = ans + curr[i];
        return ans;
    }
};