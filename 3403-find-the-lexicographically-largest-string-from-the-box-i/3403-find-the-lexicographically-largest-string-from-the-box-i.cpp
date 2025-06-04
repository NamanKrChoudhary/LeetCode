class Solution {
public:
    string answerString(string word, int numFriends) {
        long long int maxsize = word.size() - numFriends + 1;
        if(numFriends == 1) return word;
        char maxchar = word[0];
        for(int i=0; i<word.size(); i++) maxchar = max(maxchar, word[i]);
        vector<string> s;
        for(int i=0; i<word.size(); i++)
        {
            string temp = "";
            if(word[i] == maxchar)
            {
                for(int j=0; j<maxsize && i+j < word.size(); j++)
                {
                    temp.push_back(word[i+j]);
                }
                s.push_back(temp);
            }
        }
        sort(s.begin(), s.end());
        return s[s.size()-1];
    }
};