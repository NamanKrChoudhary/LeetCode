class Solution {
public:
    int longestValidParentheses(string s) {
        long long int n = s.size();
        long long int maxx = 0;
        long long int curr = 0;
        for(int i=0,j=0; i<n && j<n;)
        {
            if(s[j] == '(') {curr = curr + 1; j = j+1;}
            else 
            {
                curr = curr-1;
                if(curr == 0) {long long int temp = j-i+1; maxx = max(maxx, temp); j=j+1;}
                else if(curr < 0) {curr = 0; i = j+1; j = j+1;}
                else {j = j+1;}
            }
        }
        curr = 0;
        for(int i=n-1,j=n-1; i>=0 && j>=0;)
        {
            if(s[j] == ')') {curr = curr + 1; j=j-1;}
            else
            {
                curr = curr-1;
                if(curr==0) {long long int temp = i-j+1; maxx = max(maxx, temp); j = j-1;}
                else if(curr < 0) {curr = 0; i = j-1; j = j-1;}
                else {j = j-1;}
            }
        }
        return maxx;
    }
};