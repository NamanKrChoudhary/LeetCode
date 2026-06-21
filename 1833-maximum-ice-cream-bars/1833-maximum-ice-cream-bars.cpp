class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        long long int maxx = 0;
        for(long long int i=0; i<costs.size(); i++) if(maxx < costs[i]) maxx = costs[i];
        vector<long long int> arr(maxx+1,0);
        for(long long int i=0; i<costs.size(); i++) arr[costs[i]]++;
        long long int curr = coins;
        long long int ice = 0;
        for(long long int i=1; i<=maxx; i++)
        {
            if(curr <= i*arr[i]) 
            {
                ice = ice + (curr/i);
                break;
            }
            else
            {
                curr = curr - (i*arr[i]);
                ice = ice + arr[i];
            }
        }
        return ice;
    }
};