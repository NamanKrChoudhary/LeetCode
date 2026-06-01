class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long int minn = 0, maxx = 0;
        long long int curr = 0, n = differences.size();
        for(long long int i=0; i<n; i++)
        {
            curr = curr + differences[i];
            maxx = max(maxx, curr);
            minn = min(minn, curr);
        }
        long long int actdiff = maxx - minn, reqdiff = upper - lower;
        if(reqdiff < actdiff) return 0;
        return reqdiff - actdiff + 1;
    }
};