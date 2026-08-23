class Solution {
public:
    bool sumGame(string num) {
        long long int n = num.size();
        long long int a = 0, b = 0, aq = 0, bq = 0;
        for(int i=0; i<n/2; i++)
        {
            if(num[i] == '?') aq = aq + 1;
            else a = a + (num[i]-'0');
        }
        for(int i=n/2; i<n; i++)
        {
            if(num[i] == '?') bq = bq + 1;
            else b = b + (num[i]-'0');
        }
        if(aq > bq) 
        {
            aq = aq - bq; 
            bq = 0;
            if(a > b) return true;
        }
        else if(bq > aq) 
        {
            bq = bq-aq; 
            aq = 0;
            if(b > a) return true;
        }
        else if(bq == aq) 
        {
            if(a != b) return true;
            else return false;
        }
        long long int diff = abs(a-b);
        long long int moves = max(aq, bq);
        //cout << diff << " " << moves << endl;
        if(moves%2 == 1) return true;
        if((moves/2)*9 == diff) return false;
        return true;
    }
};