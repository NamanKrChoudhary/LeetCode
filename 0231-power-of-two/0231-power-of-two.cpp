class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n < 0) return false;
        if (n == 1)
        {
            return true;
        }
        else 
        {
            while (n != 0)
            {
                if ((n%2) == 0)
                {
                    n = n/2;
                }
                else if (n == 1)
                {
                    return true;
                }
                else return false;
            }
        } 
        return false;     
    }
};