class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        long long int n = seq.size();
        vector<int> arr(n, 0);
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(seq[i] == '(')
            {
                long long int curr = 0;
                if(st.empty()) curr = 0;
                else curr = (st.top()+1)%2;
                st.push(curr);
                arr[i] = curr;
            }
            else
            {
                arr[i] = st.top();
                st.pop();
            }
        }
        return arr;
    }
};