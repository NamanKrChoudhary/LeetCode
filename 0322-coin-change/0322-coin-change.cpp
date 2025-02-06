class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> arr(amount+1);
        for(int i=0; i<=amount; i++) arr[i] = INT_MAX-1;
        arr[0] = 0;
        for(int i=1; i<=amount; i++)
        {
            int temp = INT_MAX-1;
            for(int j=0; j<coins.size(); j++)
            {
                if(coins[j] == i){temp = 1; break;}
                if(coins[j] < i) temp = min(temp, arr[i-coins[j]]+1);
            }
            arr[i] = temp;
        }
        if(arr[amount] == INT_MAX-1) return -1;
        else return arr[amount];
    }
};