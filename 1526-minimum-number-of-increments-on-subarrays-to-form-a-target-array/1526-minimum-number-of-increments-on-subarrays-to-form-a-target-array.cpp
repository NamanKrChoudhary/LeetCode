class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        long long int n = target.size();
        stack<long long int> st;
        vector<pair<long long int, long long int>> smaller(n, {-1, -1});
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && st.top() > target[i]) st.pop();
            if(!st.empty()) smaller[i].first = st.top();
            st.push(target[i]);
        }
        stack<long long int> st1;
        for(int i=n-1; i>=0; i--)
        {
            while(!st1.empty() && st1.top() >= target[i]) st1.pop();
            if(!st1.empty()) smaller[i].second = st1.top();
            st1.push(target[i]);
        }
        long long int req = 0;
        for(int i=0; i<n; i++)
        {
            if(smaller[i].first == -1 && smaller[i].second == -1) req = req + target[i];
            else if(smaller[i].first == target[i]) continue;
            //else if(smaller[i].first == -1) req = req + target[i];
            //else if(smaller[i].first != target[i]) req = req + target[i] - smaller[i].first;
            else req = req + (target[i]-max(smaller[i].first, smaller[i].second));
        }
        return req;
    }
};