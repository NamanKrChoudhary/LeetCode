class Solution {
public:
    bool hasSameDigits(string s) {
        long long int n = s.size();
        vector<int> arr(n);
        for(int i=0; i<n; i++) arr[i] = s[i]-'0';
        for(int i=n-1; i>=2; i--)
        {
            vector<int> temp(i);
            for(int j=1; j<=i; j++) temp[j-1] = (arr[j-1]+arr[j])%10;
            if(i == 2 && temp[0] == temp[1]) return true;
            arr = temp;
        }
        return false;
    }
};