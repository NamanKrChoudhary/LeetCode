class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> arr(coins.size(), vector<int>(amount+1));
        for(int i=0; i<coins.size(); i++) arr[i][0] = 1; 
        if(coins[0] <= amount) arr[0][coins[0]] = 1;
        for(int i=0; i<coins.size(); i++)
        {
            for(int j=1; j<= amount; j++)
            {
                int temp = 0;
                if(i>0) temp = temp + arr[i-1][j];
                if(coins[i] <= j) temp = temp + arr[i][j-coins[i]];
                arr[i][j] = temp;
            }
        }
        return arr[coins.size()-1][amount];
    }
};