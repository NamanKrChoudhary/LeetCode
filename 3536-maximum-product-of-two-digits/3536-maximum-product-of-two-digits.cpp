class Solution {
public:
    int maxProduct(int n) {
        vector<int> digs;
        long long int temp = n;
        while(temp)
        {
            digs.push_back(temp%10);
            temp = temp/10;
        }
        sort(digs.rbegin(), digs.rend());
        return digs[0]*digs[1];
    }
};