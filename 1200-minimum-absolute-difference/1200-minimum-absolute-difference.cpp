class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        long long int n = arr.size();
        sort(arr.begin(), arr.end());
        long long int minn = 1e5;
        for(int i=1; i<n; i++) minn = min(minn, static_cast<long long int>(arr[i]-arr[i-1]));
        vector<vector<int>> req;
        for(int i=1; i<n; i++) if(arr[i]-arr[i-1] == minn) req.push_back({arr[i-1], arr[i]});
        return req;
    }
};