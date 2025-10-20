class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        long long int n = operations.size();
        long long int a = 0;
        for(int i=0; i<n; i++)
        {
            if(operations[i][0] == '-' || operations[i][1] == '-') a = a-1;
            else a = a+1;
        }
        return a;
    }
};