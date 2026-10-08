class Solution {
public:
    bool checkValidString(string s) {
        long long int stars = 0;
        long long int curr = 0;
        long long int n = s.size();
        vector<long long int> currstate(n);
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(') curr = curr + 1;
            else if(s[i] == ')') curr = curr-1;
            else if(s[i] == '*') stars = stars + 1;
            if(curr < 0)
            {
                if(stars > 0) {stars = stars-1; curr = 0;}
                else return false;
            }
            currstate[i] = curr;
        }
        if(currstate[n-1] == 0) return true;
        long long int minn = currstate[n-1];
        for(int i=n-1; i>=0; i--)
        {
            minn = min(minn, currstate[i]);
            if(minn == 0) return false;
            if(s[i] == '*') {minn = minn-1; curr = curr-1;}
            if(curr == 0) return true;
        }
        if(curr == 0) return true;
        else return false;
    }
};