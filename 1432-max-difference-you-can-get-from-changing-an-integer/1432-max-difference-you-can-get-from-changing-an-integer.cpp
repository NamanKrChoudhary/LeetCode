class Solution {
public:
    int maxDiff(int num) {
        vector<long long int> arr;
        long long int num1 = num;
        while(num1)
        {
            arr.push_back(num1%10);
            num1 = num1/10;
        }
        long long int change1 = 9, tochange1 = -1;
        reverse(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++) if(arr[i] != change1) {tochange1 = arr[i]; break;}
        long long int change2 = 0, tochange2 = -1;
        if(arr[0] != 1) {tochange2 = arr[0]; change2 = 1;}
        else
        {
            for(int i=1; i<arr.size(); i++) if(arr[i] != change2 && arr[i] != 1) {tochange2 = arr[i]; break;}
        }
        vector<long long int> a = arr;
        for(int i=0; i<arr.size(); i++) if(a[i] == tochange1) a[i] = change1;
        vector<long long int> b = arr;
        for(int i=0; i<arr.size(); i++) if(b[i] == tochange2) b[i] = change2;
        long long int aa = 0, bb = 0;
        for(int i=0; i<a.size(); i++)
        {
            aa = aa*10;
            aa = aa + a[i];
            bb = bb*10;
            bb = bb + b[i];
        }
        return aa - bb;
    }
};