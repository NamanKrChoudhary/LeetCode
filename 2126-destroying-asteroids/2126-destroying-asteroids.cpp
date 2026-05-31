class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long int n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());
        long long int curr = mass;
        for(int i=0; i<n; i++)
        {
            if(curr < asteroids[i]) return false;
            curr = curr + asteroids[i];
        }
        return true;
    }
};