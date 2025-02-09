class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> arr(text1.size(), vector<int>(text2.size()));
        bool check = false;
        for(int i=0; i<text2.size(); i++)
        {
            if(text1[0] == text2[i]) {check = true; arr[0][i] = 1;}
            else if(check) arr[0][i] = 1;
        }
        for(int i=1; i<text1.size(); i++)
        {
            int temp = 0;
            for(int j=0; j<text2.size(); j++)
            {
                int check1 = arr[i-1][j];
                int check2 = 0;
                if(text1[i] == text2[j] && j>0) check2 = arr[i-1][j-1] + 1;
                else if(text1[i] == text2[j]) check2 = 1;
                temp = max(temp, check1); temp = max(temp, check2);
                arr[i][j] = temp;
            }
        }
        int ans = 0;
        for(int i=0; i<text2.size(); i++) ans = max(ans, arr[text1.size()-1][i]);
        return ans;
    }
};