class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> vis(fruits.size(), false);
        for(int i=0; i<fruits.size(); i++)
        {
            for(int j=0; j<baskets.size(); j++)
            {
                if(baskets[j] >= fruits[i] && !vis[j])
                {
                    vis[j] = true;
                    break;
                }
            }
        }
        long long int curr = 0;
        for(int i=0; i<fruits.size(); i++) if(!vis[i]) curr = curr + 1;
        return curr;
    }
};