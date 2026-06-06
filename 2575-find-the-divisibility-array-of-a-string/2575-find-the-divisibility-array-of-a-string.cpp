class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> req(n,0);
        long long int curr = 0;
        for(int i=0; i<n; i++)
        {
            curr = curr*10;
            curr = curr + (word[i]-'0');
            curr = curr%m;
            if(curr == 0) req[i] = 1;
        }
        return req;
    }
};