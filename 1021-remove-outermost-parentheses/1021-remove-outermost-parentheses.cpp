class Solution {
public:
    string removeOuterParentheses(string s) {
        long long int n = s.size();
        vector<bool> marked(n, 0);
        stack<long long int> st;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(') st.push(i);
            else 
            {
                long long int curr = st.top();
                st.pop();
                if(st.empty()) {marked[i] = true; marked[curr] = true;}
            }
        }
        string req = "";
        for(int i=0; i<n; i++) if(marked[i] == false) req.push_back(s[i]);
        return req;
    }
};