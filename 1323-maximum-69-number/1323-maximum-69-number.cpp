class Solution {
public:
    int maximum69Number (int num) {
        long long int temp = num;
        vector<int> arr;
        while(temp) {arr.push_back(temp%10); temp = temp/10;}
        reverse(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] == 6) {arr[i] = 9; break;}
        }
        temp = 0;
        for(int i=0; i<arr.size(); i++) temp = (temp*10) + arr[i];
        return temp;
    }
};