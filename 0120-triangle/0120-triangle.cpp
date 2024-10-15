class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> arr(triangle[triangle.size()-1].size());
        for(int i=triangle.size()-1; i>=0; i--)
        {
            vector<int> temp(triangle[triangle.size()-1].size());
            for(int j=triangle[i].size()-1; j>=0; j--)
            {
                int down = INT_MAX;
                int downright = INT_MAX;
                if(j<triangle.size()-1)
                {
                    down = arr[j];
                    downright = arr[j+1];
                }
                if(down == INT_MAX) {temp[j] = triangle[i][j]; continue;}
                else temp[j] = triangle[i][j] + min(down, downright);
            }
            arr = temp;
        }
        return arr[0] ;
    }
};