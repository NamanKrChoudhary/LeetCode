class Solution {
public:
    int minOperations(string s) {
        sort(s.begin(), s.end());
        long long int req = 26;
        char curr = 'a';
        for(int i=0; i<s.size(); i++) if(s[i] != 'a') {curr = s[i]; break;}
        if(curr != 'a') return 26-(curr-'a');
        else return 0;
    }
};