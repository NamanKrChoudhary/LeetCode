class Solution {
public:
    bool doesAliceWin(string s) {
        set<char> ss = {'a', 'e', 'i', 'o', 'u'};
        bool check = false;
        for(int i=0; i<s.size(); i++)
        {
            if(ss.find(s[i]) != ss.end()){return true;}
        }
        return false;
    }
};