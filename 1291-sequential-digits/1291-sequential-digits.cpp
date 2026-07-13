class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // long long int tens = 1;
        // while(low/tens != 0 && tens != low) tens = tens*10;
        vector<int> digs = {1,2,3,4,5,6,7,8,9};
        vector<int> lowdigs;
        long long int temp = low;
        while(temp) 
        {
            lowdigs.push_back(temp%10);
            temp = temp/10;
        }
        long long int len = lowdigs.size();
        int i = 0, j = 0;
        reverse(lowdigs.begin(), lowdigs.end());
        for(int k=0; k<9; k++) if(lowdigs[0] == digs[k]) {i = k; break;}
        j = i+len-1;
        if(j>=9)
        {
            len = len + 1;
            i = 0;
            j = i+len-1;
        }
        vector<int> req;
        if(j >= 9) return req;
        long long int curr = 0;
        long long int tens = 1;
        for(int k=i; k<=j; k++) {curr = curr*10; curr = curr + digs[k]; tens = tens*10;}
        tens = tens/10;
        if(curr <= high && curr >= low) req.push_back(curr);
        while(curr <= high)
        {
            i = i+1;
            j = j+1;
            if(j >= 9)
            {
                len = len + 1;
                i = 0;
                j = i+len-1;
                if(j >= 9) break;
                tens = tens*10;
                curr = 0;
                for(int k=0; k<=j; k++) {curr = curr*10; curr = curr + digs[k];} 
            }
            else 
            {
                curr = curr%tens;
                curr = curr * 10;
                curr = curr + digs[j];
            }
            if(curr <= high) req.push_back(curr);
        }
        return req;
    }
};