class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> pos(n+1, false);
        vector<long long int> arr;
        for(int i=1; i*i <=n; i++) arr.push_back(i*i);
        pos[0] = false;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<arr.size() && arr[j] <= i; j++)
            {
                //cout << j << " ";
                if(pos[i-arr[j]] == false) {pos[i] = true; break;}
            }
        }
        return pos[n];
    }
};