class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        vector<int> a = players, b = trainers;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        long long int maxx = 0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]<=b[j]) {maxx = maxx + 1; i = i+1; j = j+1;}
            else j = j+1;
        }
        return maxx;
    }
};