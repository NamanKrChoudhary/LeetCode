class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long int minnadd = 0, maxxadd = 0;
        long long int curr = 0, n = differences.size();
        for(long long int i=0; i<n; i++)
        {
            curr = curr + differences[i];
            maxxadd = max(maxxadd, curr);
            minnadd = min(minnadd, curr);
        }
        long long int actdiff = maxxadd - minnadd, reqdiff = upper - lower;
        if(reqdiff < actdiff) return 0;
        return reqdiff - actdiff + 1;
    }
};