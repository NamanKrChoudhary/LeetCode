class Solution {
public:
    int minOperations(int k) {
        long long int req = k-1;
        long long int temp = 1;
        for(int i=1; i<k; i++)
        {
            temp = temp + 1;
            long long int curr = (k/temp);
            if(k%temp == 0) curr = curr - 1;
            curr = curr + i;
            req = min(req, curr);
        }
        return req;
    }
};