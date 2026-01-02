class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        map<pair<long long int, long long int>, long long int> lastavl;
        for(int i=0; i<cells.size(); i++) lastavl[{cells[i][0]-1, cells[i][1]-1}] = i;
        priority_queue<vector<long long int>> q;
        vector<vector<long long int>> arr(row, vector<long long int>(col, 0));
        for(int i=0; i<col; i++) {arr[0][i] = lastavl[{0, i}]; q.push({arr[0][i], 0, i});}
        while(!q.empty())
        {
            vector<long long int> curr = q.top();
            q.pop();
            long long int curri = curr[1], currj = curr[2];
            if(curri < row-1)
            {
                long long int temp = min(curr[0], lastavl[{curri+1, currj}]);
                if(temp > arr[curri+1][currj])
                {
                    arr[curri+1][currj] = temp;
                    q.push({temp, curri+1, currj});
                }
            }
            if(curri > 0)
            {
                long long int temp = min(curr[0], lastavl[{curri-1, currj}]);
                if(temp > arr[curri-1][currj])
                {
                    arr[curri-1][currj] = temp;
                    q.push({temp, curri-1, currj});
                }
            }
            if(currj < col-1)
            {
                long long int temp = min(curr[0], lastavl[{curri, currj+1}]);
                if(temp > arr[curri][currj+1])
                {
                    arr[curri][currj+1] = temp;
                    q.push({temp, curri, currj+1});
                }
            }
            if(currj > 0)
            {
                long long int temp = min(curr[0], lastavl[{curri, currj-1}]);
                if(temp > arr[curri][currj-1])
                {
                    arr[curri][currj-1] = temp;
                    q.push({temp, curri, currj-1});
                }
            }
        }
        long long int req = 0;
        for(int i=0; i<col; i++) req = max(req, arr[row-1][i]);
        return req;
    }
};