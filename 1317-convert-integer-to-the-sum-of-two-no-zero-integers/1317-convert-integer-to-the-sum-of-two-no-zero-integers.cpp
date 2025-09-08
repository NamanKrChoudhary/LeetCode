class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        long long int temp = n;
        vector<int> dig1, dig2;
        while(temp)
        {
            int currdig = temp%10;
            temp = temp/10;
            if(currdig == 0)
            {
                dig1.push_back(1);
                dig2.push_back(9);
                temp = temp-1;
            }
            else if(currdig == 1)
            {
                dig1.push_back(2);
                dig2.push_back(9);
                temp = temp-1;
            }
            else
            {
                dig1.push_back(currdig/2);
                dig2.push_back(currdig-(currdig/2));
            }
        }
        int no1 = 0, no2 = 0;
        for(int i=dig1.size()-1; i>=0; i--)
        {
            no1 = (no1*10)+dig1[i];
            no2 = (no2*10)+dig2[i];
        }
        vector<int> nos = {no1, no2};
        return nos;
    }
};