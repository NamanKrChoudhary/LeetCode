class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<long long int> st;
        long long int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(') st.push(-1);
            else
            {
                if(st.top() == -1)
                {
                    st.pop();
                    long long int curr = 1;
                    while(!st.empty() && st.top() != -1)
                    {
                        curr = curr + st.top();
                        st.pop();
                    }
                    //st.pop();
                    st.push(curr);
                }
                else
                {
                    long long int curr = 0;
                    while(!st.empty() && st.top() != -1) 
                    {
                        curr = curr + st.top();
                        st.pop();
                    }
                    st.pop();
                    curr = curr*2;
                    while(!st.empty() && st.top() != -1)
                    {
                        curr = curr + st.top();
                        st.pop();
                    }
                    st.push(curr);
                }
            }
        }
        return st.top();
    }
};