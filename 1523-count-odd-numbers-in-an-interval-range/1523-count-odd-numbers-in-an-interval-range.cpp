class Solution {
public:
    int countOdds(int low, int high) {
        long long int diff = high - low;
        if(diff%2 == 0)
        {
            if(low%2 == 1) return (diff/2)+1;
            else return diff/2;
        }
        else return (diff+1)/2;
    }
};