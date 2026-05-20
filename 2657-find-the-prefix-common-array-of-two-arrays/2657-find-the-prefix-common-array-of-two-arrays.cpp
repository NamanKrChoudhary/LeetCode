class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prev(n+1, 0);
        vector<int> c(n);
        long long int curr = 0;
        for(int i=0; i<n; i++)
        {
            prev[A[i]] = prev[A[i]] + 1;
            if(prev[A[i]] == 2) curr = curr + 1;
            prev[B[i]] = prev[B[i]] + 1;
            if(prev[B[i]] == 2) curr = curr + 1;
            c[i] = curr;
        }
        return c;
    }
};