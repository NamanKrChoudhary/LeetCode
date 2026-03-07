class Solution {
public:
    int minFlips(string s) {
        long long int n = s.size();
        //cout << n << endl;
        vector<pair<long long int, long long int>> forward(n,{0,0}), backward(n,{0,0});
        if(s[0] == '0') forward[0].second = 1;
        else forward[0].first = 1;
        if(s[n-1] == '0') backward[n-1].second = 1;
        else backward[n-1].first = 1;
        for(int i=1; i<n; i++)
        {
            if(s[i] == '0')
            {
                forward[i].first = forward[i-1].second;
                forward[i].second = forward[i-1].first + 1;
            }
            else
            {
                forward[i].first = forward[i-1].second + 1;
                forward[i].second = forward[i-1].first;
            }
        }
        for(int i=n-2; i>=0; i--)
        {
            if(s[i] == '0')
            {
                backward[i].first = backward[i+1].second;
                backward[i].second = backward[i+1].first + 1;
            }
            else
            {
                backward[i].first = backward[i+1].second + 1;
                backward[i].second = backward[i+1].first;
            }
        }
        long long int minn = min(forward[n-1].first, forward[n-1].second);
        for(int i=2; i<n; i++) 
        {
            if(n%2 == 0) minn = min(minn, min((forward[i-1].first+backward[i].second), (forward[i-1].second + backward[i].first)));
            else minn = min(minn, min((forward[i-1].first + backward[i].first), (forward[i-1].second + backward[i].second)));
        }
        return minn;
        // 10101001101
    }
};