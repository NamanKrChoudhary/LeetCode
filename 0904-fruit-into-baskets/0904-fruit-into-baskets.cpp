class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<long long int, long long int> mp;
        long long int maxx = 0;
        for(int i=0,j=0; i<fruits.size() && j<fruits.size();)
        {
            if(j<fruits.size())
            {
                if(mp.find(fruits[j]) != mp.end() || mp.size() < 2) 
                {
                    mp[fruits[j]]++;
                    long long int curr = 0;
                    for(auto k: mp) curr = curr + k.second;
                    maxx = max(maxx, curr);
                    j = j+1;
                }
                else 
                {
                    if(mp[fruits[i]] <= 1) mp.erase(fruits[i]);
                    else mp[fruits[i]]--;
                    i = i+1;
                    long long int curr = 0;
                    for(auto k: mp) curr = curr + k.second;
                    maxx = max(maxx, curr);
                }
            }
        }
        return maxx;
    }
};