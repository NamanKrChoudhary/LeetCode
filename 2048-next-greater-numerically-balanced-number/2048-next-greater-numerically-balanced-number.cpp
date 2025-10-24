class Solution {
public:
    int nextBeautifulNumber(int n) {
        for(int i=n+1; i<=1e7; i++)
        {
            vector<int> freq(10,0);
            long long int temp = i;
            while(temp) {freq[temp%10]++; temp = temp/10;}
            bool check = true;
            for(int j=0; j<10; j++) if(freq[j] != j && freq[j] != 0) {check = false; break;}
            if(check) return i;
        }
        return 0;
    }
};