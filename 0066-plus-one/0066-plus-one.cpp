class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int curr = 1;
        for(int i=digits.size()-1; i>=0; i--)
        {
            digits[i] = digits[i]+curr;
            curr = digits[i]/10;
            digits[i] = digits[i]%10;
        }
        if(curr > 0) 
        {
            vector<int> arr = {curr};
            for(int i=0; i<digits.size(); i++) arr.push_back(digits[i]);
            return arr;
        }
        else return digits;
    }
};