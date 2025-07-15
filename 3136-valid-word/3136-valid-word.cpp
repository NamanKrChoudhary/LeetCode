class Solution {
public:
    bool isValid(string word) {
        set<char> vow = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I','O','U'};
        if(word.size() < 3) return false;
        bool check = true, vowl = false, cons = false;
        for(int i=0; i<word.size(); i++)
        {
            if(word[i]-'0' <=9) continue;
            else if(word[i]-'a' < 26 || word[i]-'A' < 26)
            {
                if(vow.find(word[i]) != vow.end()) vowl = true;
                else cons = true;
            }
            else check = false;
        }
        return (check & vowl & cons);
    }
};