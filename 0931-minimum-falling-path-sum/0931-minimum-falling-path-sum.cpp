class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> arr(matrix.size());
        for(int i=0; i<matrix.size(); i++)
        {
            vector<int> temp(matrix.size());
            for(int j=0; j<matrix.size(); j++)
            {
                int up = INT_MAX;
                int upleft = INT_MAX;
                int upright = INT_MAX;
                if(i>0)
                {
                    if(j>0) upleft = arr[j-1];
                    up = arr[j];
                    if(j<matrix.size()-1) upright = arr[j+1];
                }
                if(up == INT_MAX) {temp[j] = matrix[i][j]; continue;}
                temp[j] = matrix[i][j] + min(up, min(upleft, upright));
            }
            arr = temp;
        }
        return *min_element(arr.begin(), arr.end());
    }
};