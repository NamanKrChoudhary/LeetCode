class Solution {
public:
    int minCut(string s) {
        if(s.size() == 1) return 0;
        vector<int> t(s.size());
        for(int i=s.size()-1; i>=0; i--)
        {
            deque<char> st, m, e;
            int temp = s.size()-1-i;
            for(int j=i; j<s.size(); j++)
            {
                e.push_front(s[j]);
                if(m.empty()) {m.push_back(e[e.size()-1]); e.pop_back();}
                else {st.push_back(m[0]); m.pop_back();}
                if(st == e)
                {
                    int curr;
                    if(j == s.size()-1) curr = 0;
                    else curr = 1 + t[j+1];
                    temp = min(temp, curr);
                }
            }
            t[i] = temp;
        }
        return t[0];
    }
};