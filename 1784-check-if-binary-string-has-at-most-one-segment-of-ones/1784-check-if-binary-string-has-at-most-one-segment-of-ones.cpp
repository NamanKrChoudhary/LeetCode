class Solution {
public:
    bool checkOnesSegment(string s) {
        long long int n = s.size();
        long long int cnt = 0;
        bool check = false;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '0') check = false;
            else if(check == false) {check = true; cnt = cnt + 1;}
        }
        if(cnt > 1) return false;
        else return true;
    }
};