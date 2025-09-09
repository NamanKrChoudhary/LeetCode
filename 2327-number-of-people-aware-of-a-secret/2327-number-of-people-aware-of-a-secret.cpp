#define MOD 1000000007
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> added(n+1,0);
        added[0] = 0;
        added[1] = 1;
        int curr = 1;
        int toAdd = 0;
        for(int i = 2;i <= n;i++){
            int lfi = i - forget, ldi = i - delay;
            if(ldi > 0) toAdd = (toAdd + added[ldi]) % MOD;
            if(lfi > 0) toAdd = (toAdd - added[lfi] + MOD) % MOD;
            added[i] = toAdd;
            curr = (curr + toAdd) % MOD;
            if(lfi > 0) curr = (curr - added[lfi] + MOD) % MOD;
        }
        return curr;
    }
};