class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        vector<long long int> arr;
        for(auto i: requests)
        {
            if(i == start) continue;
            arr.push_back(i);
        }
        sort(arr.begin(), arr.end());
        long long int len = arr.size();
        long long int i= -1, j = -1;
        for(int k = 0; k<len; k++) 
        {
            if(arr[k] < start) i = k;
            else if(arr[k] > start) {j = k; break;}
        }
        if(i == -1)
        {
            long long int req = 0;
            for(int k=0; k<len; k++) req = req + (arr[k]-start);
            return req;
        }
        else if(j == -1)
        {
            long long int req = 0;
            for(int k=0; k<len; k++) req = req + (start-arr[k]);
            return req;
        }
        vector<vector<long long int>> dp(len, vector<long long int>(len));
        dp[i][j] = (len*(start - arr[i])) + ((len-1)*(arr[j]-arr[i]));
        dp[j][i] = (len*(arr[j]-start)) + ((len-1)*(arr[j]-arr[i]));
        long long int temp = (len*(arr[j]-start));
        for(int currj = j+1; currj < len; currj++)
        {
            dp[i][currj] = dp[i][currj-1] + ((arr[currj]-arr[currj-1])*(len-(currj-i)));
            temp = temp + ((arr[currj]-arr[currj-1])*(len-(currj-j)));
            dp[currj][i] = temp + ((arr[currj]-arr[i])*(len-(currj-j+1)));
        }
        temp = (len*(start - arr[i]));
        //cout << temp << endl;
        for(int curri = i-1; curri >=0; curri--)
        {
            dp[j][curri] = dp[j][curri+1] + ((arr[curri+1]-arr[curri])*(len-(j-curri)));
            temp = temp + ((arr[curri+1]-arr[curri])*(len-(i-curri)));
            //cout << temp << endl;
            dp[curri][j] = temp + ((arr[j]-arr[curri])*(len-(i-curri+1)));
        }
        for(int curri = i-1; curri >= 0; curri--)
        {
            for(int currj = j+1; currj<len; currj++)
            {
                long long int choice1 = dp[curri+1][currj] + ((arr[currj]-arr[curri])*(len-(currj-curri)));
                long long int choice2 = dp[currj][curri+1] + ((arr[curri+1]-arr[curri])*(len-(currj-curri)));
                dp[currj][curri] = min(choice1, choice2);
                choice1 = dp[currj-1][curri] + ((arr[currj]-arr[curri])*(len-(currj-curri)));
                choice2 = dp[curri][currj-1] + ((arr[currj]-arr[currj-1])*(len-(currj-curri)));
                dp[curri][currj] = min(choice1, choice2);
            }
        }
        long long int req = min(dp[0][len-1], dp[len-1][0]);
        //if(n == 10) cout << dp[0][2] << endl;
        return req;
    }
};