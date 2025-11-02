class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> arr(m, vector<int>(n,0));
        // guard = 1, wall = 2, guarded = 3, unguarded = 0;
        for(int i=0; i<guards.size(); i++) arr[guards[i][0]][guards[i][1]] = 1;
        for(int i=0; i<walls.size(); i++) arr[walls[i][0]][walls[i][1]] = 2;
        bool check = false;
        for(int i=0; i<m; i++)
        {
            check = false;
            for(int j=0; j<n; j++)
            {
                if(arr[i][j] == 1) {check = true; continue;}
                else if(arr[i][j] == 2) {check = false; continue;}
                else if(arr[i][j] == 0 && check == true) {arr[i][j] = 3; continue;}
            }
            check = false;
            for(int j=n-1; j>=0; j--)
            {
                if(arr[i][j] == 1) {check = true; continue;}
                else if(arr[i][j] == 2) {check = false; continue;}
                else if(arr[i][j] == 0 && check == true) {arr[i][j] = 3; continue;}
            }
        }
        for(int i=0; i<n; i++)
        {
            check = false;
            for(int j=0; j<m; j++)
            {
                if(arr[j][i] == 1) {check = true; continue;}
                else if(arr[j][i] == 2) {check = false; continue;}
                else if(arr[j][i] == 0 && check == true) {arr[j][i] = 3; continue;}
            }
            check = false;
            for(int j=m-1; j>=0; j--)
            {
                if(arr[j][i] == 1) {check = true; continue;}
                else if(arr[j][i] == 2) {check = false; continue;}
                else if(arr[j][i] == 0 && check == true) {arr[j][i] = 3; continue;}
            }
        }
        long long int unguarded = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++) if(arr[i][j] == 0) unguarded = unguarded + 1;
        }
        return unguarded;
    }
};