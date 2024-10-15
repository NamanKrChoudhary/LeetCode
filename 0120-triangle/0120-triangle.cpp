class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> arr(triangle[0].size());
        for(int i=0; i<triangle.size(); i++)
        {
            vector<int> temp(triangle[i].size());
            for(int j=0; j<triangle[i].size(); j++)
            {
                int up = INT_MAX;
                int upleft = INT_MAX;
                if(i>0 && j<triangle[i].size()-1) up = arr[j];
                if(j>0) upleft = arr[j-1];
                if(up == INT_MAX && upleft == INT_MAX) {temp[j] = triangle[i][j]; cout << temp[j] << " "; continue;}
                temp[j] = triangle[i][j] + min(up, upleft);
                cout << temp[j] << " ";
            }
            cout << endl;
            arr = temp;
        }
        return *min_element(arr.begin(), arr.end());
    }
};