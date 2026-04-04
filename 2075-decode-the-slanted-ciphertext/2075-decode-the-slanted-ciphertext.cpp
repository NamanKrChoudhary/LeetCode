class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        long long int n = encodedText.size();
        long long int cols = n/rows;
        vector<vector<char>> arr(rows, vector<char>(cols,' '));
        int k = 0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                arr[i][j] = encodedText[k];
                k = k+1;
            }
        }
        string req = "";
        for(int j=0; j<cols; j++)
        {
            // string temp = "";
            // string blank = "";
            for(int row=0,col=j; row<rows && col<cols; row = row + 1, col = col + 1)
            {
                req.push_back(arr[row][col]);
                //blank.push_back(' ');
            }
            //if(temp == blank) break;
            //for(int i=0; i<temp.size(); i++) req.push_back(temp[i]);
        }
        // for(int i=0; i<rows; i++) {for(int j=0; j<cols; j++) cout << arr[i][j] << " "; cout << endl;}
        while(!req.empty() && req[req.size()-1] == ' ') req.pop_back();
        return req;
    }
};