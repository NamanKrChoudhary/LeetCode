class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        long long int n = energy.size();
        map<long long int, long long int> mp;
        for(int i=0; i<n; i++)
        {
            mp[i%k] += energy[i];
        }
        long long int maxx = LLONG_MIN;
        map<long long int, long long int> temp;
        for(auto i: mp) maxx = max(maxx, i.second);
        for(int i=0; i<n; i++)
        {
            //cout << i << " " << mp[i%k]-temp[i%k] << endl;
            maxx = max(maxx, mp[i%k]-temp[i%k]);
            temp[i%k] += energy[i];
        }
        return maxx;
    }
};