class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long int temp = k;
        long long int change = 0;
        while(temp > 1)
        {
            long long int cnt = 0;
            long long int mul = 1;
            while((mul*2)<temp) {mul = mul*2; cnt = cnt + 1;}
            if(temp%mul == 0) temp = temp/2;
            else temp = temp%mul;
            if(operations[cnt] == 1) change = change + 1;
            cout << mul << " " << cnt << " " << temp << endl;
        }
        change = change%26;
        char curr = 'a' + change;
        return curr;
    }
};