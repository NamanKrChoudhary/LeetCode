class Solution {
public:
    int totalWaviness(int num1, int num2) {
        long long int req = 0;
        for(int i=num1; i<=num2; i++)
        {
            long long int temp = i;
            vector<int> arr;
            while(temp)
            {
                arr.push_back(temp%10);
                temp = temp/10;
            }
            for(int i=2; i<arr.size(); i++)
            {
                if(arr[i-1] > arr[i-2] && arr[i-1] > arr[i]) req = req + 1;
                if(arr[i-1] < arr[i-2] && arr[i-1] < arr[i]) req = req + 1;
            }
        }
        return req;
    }
};