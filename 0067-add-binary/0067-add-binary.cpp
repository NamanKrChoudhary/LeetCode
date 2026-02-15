class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while(a.size() < b.size()) a.push_back('0');
        while(b.size() < a.size()) b.push_back('0');
        long long int n = a.size();
        int carry = 0;
        string sum;
        vector<char> mp(2,'0'); mp[1] = '1';
        for(int i=0; i<n; i++)
        {
            int curr = 0;
            if(a[i] == '1') curr = curr + 1;
            if(b[i] == '1') curr = curr + 1;
            if(carry == 1) curr = curr + 1;
            sum.push_back(mp[curr%2]);
            carry = curr/2;
        }
        if(carry == 1) sum.push_back('1');
        reverse(sum.begin(), sum.end());
        return sum;
    }
};