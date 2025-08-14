class Solution {
public:
    long long int ones(vector<vector<long long int>>& arr, long long int currn)
    {
        if(currn == 0) return 0;
        if(currn/10 == 0) return arr[0][currn];
        long long int temp = currn;
        long long int tempaft = currn;
        long long int pows = 1;
        long long int i = 0;
        while(temp/10 != 0) 
        {
            temp = temp/10;
            i++;
            pows = pows*10;
            tempaft = currn%pows;
        }
        long long int currones = ones(arr, tempaft);
        if(temp == 0) return currones;
        else if(temp == 1)
        {
            currones = currones + arr[i-1][9];
            currones = currones + tempaft+1;
        }
        else
        {
            currones = currones + arr[i][temp-1];
        }
        return currones;
    }

    int countDigitOne(int n) {
        vector<vector<long long int>> arr(10, vector<long long int>(10));
        for(int i=1; i<10; i++) arr[0][i] = 1;
        for(int i=1; i<10; i++)
        {
            for(int j=1; j<10; j++)
            {
                arr[i][j] = arr[i][j] + arr[i-1][9];
                if(j == 1) 
                {
                    arr[i][j] = arr[i][j] + arr[i-1][9];
                    arr[i][j] = arr[i][j] + pow(10, i);
                }
                else arr[i][j] = arr[i][j] + arr[i][j-1];
            }
        }
        return ones(arr, n);
    }
};