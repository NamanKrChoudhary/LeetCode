class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        long long int n = spells.size(), m = potions.size();
        vector<int> pot = potions;
        sort(pot.begin(), pot.end());
        vector<int> pairs(n);
        for(int i=0; i<n; i++)
        {
            long long int req = success/spells[i];
            if(success%spells[i] != 0) req = req+1;
            long long int reqi = lower_bound(pot.begin(), pot.end(), req) - pot.begin();
            pairs[i] = m-reqi;
        }
        return pairs;
    }
};