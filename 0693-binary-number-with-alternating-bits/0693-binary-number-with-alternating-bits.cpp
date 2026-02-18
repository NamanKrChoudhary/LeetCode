class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long int temp = n;
        vector<bool> bits;
        while(temp)
        {
            bits.push_back(temp%2);
            temp = temp/2;
        }
        bool check = true;
        for(int i=1; i<bits.size(); i++) if(bits[i] == bits[i-1]) {check = false; break;}
        return check;
    }
};