class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double st = -1e10, end = 1e10, mid = st + ((end-st)/2);
        long double req = LONG_MAX;
        vector<vector<long double>> arr(squares.size(), vector<long double>(3));
        for(int i=0; i<squares.size(); i++) for(int j=0; j<3; j++) arr[i][j] = squares[i][j];
        while(end-st >= 1e-6)
        {
            mid = st + ((end-st)/2);
            long double a = 0, b = 0;
            for(int i=0; i<arr.size(); i++)
            {
                if(arr[i][1] >= mid) b = b + (arr[i][2]*arr[i][2]);
                else
                {
                    if(arr[i][1]+arr[i][2] > mid)
                    {
                        long double above = (arr[i][1]+arr[i][2]-mid);
                        a = a + ((arr[i][2]-above)*arr[i][2]);
                        b = b + (above*arr[i][2]);
                    }
                    else a = a + (arr[i][2]*arr[i][2]);
                }
            }
            //cout << setprecision(1e-6) << mid << endl;
            //cout << a << " " << b << endl;
            if(a == b) 
            {
                req = mid;
                end = mid - 1e-6;
            }
            else if(a > b) end = mid-(1e-6);
            else if(b > a) st = mid + (1e-6);
        }
        if(req != LONG_MAX) return req;
        else return mid;
    }
};