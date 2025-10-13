class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> curr = words;
        for(int i=0; i<words.size(); i++) sort(curr[i].begin(), curr[i].end());
        vector<string> res;
        res.push_back(words[0]);
        for(int i=1; i<words.size(); i++)
        { 
            if(curr[i-1] != curr[i]) res.push_back(words[i]); 
        }
        return res;
    }
};