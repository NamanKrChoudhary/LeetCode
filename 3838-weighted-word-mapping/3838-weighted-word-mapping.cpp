class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string req = "";
        for(int i=0; i<words.size(); i++)
        {
            long long int curr = 0;
            for(int j=0; j<words[i].size(); j++) curr = curr + weights[words[i][j]-'a'];
            curr = curr%26;
            req.push_back('z'-curr);
        }
        return req;
    }
};