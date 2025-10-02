class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        long long int full = numBottles, empty = 0;
        long long int div = numExchange;
        long long int drank = 0;
        while(full+empty >= div || full > 0)
        {
            drank = drank + full;
            empty = empty + full;
            full = 0;
            while(empty >= div)
            {
                empty = empty - div;
                div = div + 1;
                full = full + 1;
            }
        }
        return drank;
    }
};