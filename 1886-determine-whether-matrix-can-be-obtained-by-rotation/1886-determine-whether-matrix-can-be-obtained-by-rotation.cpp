class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        long long int n = mat.size();
        bool check1 = true, check2 = true, check3 = true, check4 = true;
        for(int orgi=0, j1=n-1, i2=n-1, j3=0, i4=0; orgi<n; orgi++, j1--, i2--, j3++, i4++)
        {
            for(int orgj=0, i1=0, j2=n-1, i3=n-1, j4=0; orgj<n; orgj++, i1++, j2--, i3--, j4++)
            {
                if(mat[orgi][orgj] != target[i1][j1]) check1 = false;
                if(mat[orgi][orgj] != target[i2][j2]) check2 = false;
                if(mat[orgi][orgj] != target[i3][j3]) check3 = false;
                if(mat[orgi][orgj] != target[i4][j4]) check4 = false;
            }
        }
        return check1|check2|check3|check4 ;
    }
};