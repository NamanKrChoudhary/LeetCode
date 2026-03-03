class Solution {
public:
    char findKthBit(int n, int k) {
        set<long long int> less;
        set<long long int> eq; eq.insert(2);
        long long int curr = 4;
        for(int i=0; i<n; i++) 
        {
            eq.insert(curr);
            less.insert(curr-1);
            curr = curr*2;
        }
        bool check = false;
        long long int temp = k;
        while(temp>1)
        {
            if(eq.find(temp) != eq.end()) 
            {
                char req = '0';
                if(true^check == 1) req = '1';
                return req;
            }
            long long int currmax = *eq.upper_bound(temp);
            currmax = currmax/2;
            long long int currdiff = temp - currmax;
            temp = currmax - currdiff;
            check = !check;
        }
        char req = '0';
        if(0^check == 1) req = '1';
        return req;
    }
};