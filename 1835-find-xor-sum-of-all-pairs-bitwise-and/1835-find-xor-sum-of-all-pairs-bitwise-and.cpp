class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<long long int> bits1(45, 0), bits2(45, 0);
        for(int i=0; i<arr1.size(); i++)
        {
            long long int temp = arr1[i];
            //long long int currpow = 1;
            for(int i=0; i<45; i++)
            {
                if(temp%2 == 1) bits1[i] = bits1[i] + 1;
                temp = temp/2;
            }
        }
        for(int i=0; i<arr2.size(); i++)
        {
            long long int temp = arr2[i];
            for(int i=0; i<45; i++)
            {
                if(temp%2 == 1) bits2[i] = bits2[i] + 1;
                temp = temp/2;
            }
        }
        long long int req = 0, currpow = 1; 
        for(int i=0; i<45; i++)
        {
            if(bits1[i]%2 == 1 && bits2[i]%2 == 1) req = req + currpow;
            currpow = currpow*2;
        }
        return req;
    }
};