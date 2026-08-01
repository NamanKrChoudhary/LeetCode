class Solution {
public:
    bool fix(string& target, multiset<char>& ms, string& req, long long int curri)
    {
        long long int currval = 0;
        if(ms.lower_bound(target[curri]) == ms.end()) currval = -1;
        else
        {
            char curr = *ms.lower_bound(target[curri]);
            if(curr == target[curri]) currval = 1;
            else currval = 2;
        }
        if((curri == target.size() -1 && currval == 1) || currval == -1) return false;
        if(currval == 1)
        {
            req.push_back(target[curri]);
            auto it = ms.find(target[curri]);
            ms.erase(it);
            bool check = fix(target, ms, req, curri+1);
            if(check == true) return true;
            else 
            {
                req.pop_back();
                ms.insert(target[curri]);
                if(ms.upper_bound(target[curri]) == ms.end()) return false;
                else
                {
                    char currchar = *ms.upper_bound(target[curri]);
                    req.push_back(currchar);
                    auto it = ms.upper_bound(target[curri]);
                    ms.erase(it);
                    for(auto i: ms) req.push_back(i);
                    return true;
                }
            }
        }
        else if(currval == 2)
        {
            char currchar = *ms.lower_bound(target[curri]);
            req.push_back(currchar);
            auto it = ms.lower_bound(target[curri]);
            ms.erase(it);
            for(auto i: ms) req.push_back(i);
            return true;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        multiset<char> ms;
        for(auto i: s) ms.insert(i);
        string req = "";
        bool check = fix(target, ms, req, 0);
        return req;
    }
};