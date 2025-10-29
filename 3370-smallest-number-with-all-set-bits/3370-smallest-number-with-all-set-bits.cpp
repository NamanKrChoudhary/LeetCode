class Solution {
public:
    int smallestNumber(int n) {
        long long int temp = n;
        long long int cnt = 0;
        while(temp) {cnt = cnt + 1; temp = temp/2;}
        long long int setbit = 1<<cnt;
        setbit = setbit-1;
        return setbit;
    }
};