class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long int one = min(a,b);
        long long int two = max(a,b);
        long long int pp = 0;
        while(one*pp<=two)
        {
            if(one*(pp+1) > two) break;
            pp = pp+1;
        }
        pp = pp+1;
        long long int i = 0;
        long long int curr = 0;
        for(; i<=n; i++)
        {
            if((i*((2*pp)+i-1)/2) > n) {--i; break;}
        }
        curr = n - (i*((2*pp)+i-1)/2);
        pp = pp-1;
        if(curr <= pp) {return pow(one, (pp*i)) * pow(one,curr) ;}
        else {return pow(two,(curr-pp)) * pow(one,(pp*(i+1-(curr-pp))));}
        return 0;
    }
};