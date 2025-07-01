class Solution {
public:
    int possibleStringCount(string word) {
        vector<long long int> mp;
        long long int cnt = 0; char prev = word[0];
        for(int i=0; i<word.size(); i++)
        {
            if(word[i] == prev) cnt = cnt + 1;
            else
            {
                mp.push_back(cnt); 
                prev = word[i];
                cnt =1;
            }
        }
        mp.push_back(cnt);
        long long int ans = 1;
        for(auto i: mp) ans = ans + (i) - 1;
        return ans;
    }
};