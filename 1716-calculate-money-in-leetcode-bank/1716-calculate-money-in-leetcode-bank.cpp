class Solution {
public:
    int totalMoney(int n) {
        long long int week = 0, counter = 0, sum = 0;
        for(int i=0; i<n; i++)
        {
            if(i%7 == 0)
            {
                week = week + 1;
                counter = week;
                sum = sum + counter;
            }
            else
            {
                counter = counter + 1;
                sum = sum + counter;
            }
        }
        return sum;
    }
};