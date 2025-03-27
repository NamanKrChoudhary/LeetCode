class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> arr; arr.push_back(0);
        for(int i=0; i<cuts.size(); i++) arr.push_back(cuts[i]);
        arr.push_back(n);
        sort(arr.begin(), arr.end());
        int ss = arr.size();
        vector<vector<int>> v(ss, vector<int>(ss));
        for(int i=ss-1; i>=0; i--)
        {
            for(int j=i+2; j<ss; j++)
            {
                long long int temp = LONG_MAX;
                for(int k=i+1; k<j; k++)
                {
                    long long int curr = (arr[j]-arr[i])+ v[i][k] + v[k][j];
                    temp = min(temp, curr);
                }
                v[i][j] = temp;
            }
        }
        return v[0][ss-1];
    }
};