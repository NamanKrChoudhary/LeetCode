class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<long long int, long long int> mp;
        long long int n = answers.size();
        for(int i=0; i<n; i++) mp[answers[i]]++;
        int ans = 0;
        for(auto i: mp)
        {
            if(i.first == 0) {ans = ans+i.second; continue;}
            ans = ans + (i.second/(i.first+1))*(i.first+1);
            cout << i.first << " " << i.second << endl;
            if((i.second)%(i.first+1) != 0) ans = ans + i.first+1;
            cout << i.first << " " << i.second << endl;
        }
        return ans;
    }
};