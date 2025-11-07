class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long int n = stations.size();
        vector<long long int> currpow(n);
        long long int sumpow = 0;
        for(int i=0; i<n; i++) currpow[i] = stations[i];
        for(int i=0; i<n; i++)
        {
            currpow[i] = currpow[i] + sumpow;
            sumpow = sumpow + stations[i];
            if(i-r >= 0) sumpow = sumpow - stations[i-r];
        }
        sumpow = 0;
        for(int i=n-1; i>=0; i--)
        {
            currpow[i] = currpow[i] + sumpow;
            sumpow = sumpow + stations[i];
            if(i+r <= n-1) sumpow = sumpow - stations[i+r];
        }
        //for(int i=0; i<n; i++) cout << currpow[i] << " "; cout << endl;
        long long int st = 0, end = 1e15, mid = st + ((end-st)/2);
        long long int maxx = 0;
        while(st <= end)
        {
            mid = st + ((end-st)/2);
            long long int avl = k;
            long long int relevant = 0;
            bool check = true;
            queue<pair<long long int, long long int>> ind;
            //cout << mid << endl;
            vector<long long int> pows(n);
            vector<long long int> rel(n);
            for(int i=0; i<n; i++)
            {
                //long long int temp = currpow[i];
                rel[i] = relevant;
                if(currpow[i]+relevant < mid)
                {
                    if(mid-(currpow[i]+relevant) > avl)
                    {
                        check = false;
                        break;
                    }
                    else
                    {
                        avl = avl-(mid-(currpow[i]+relevant));
                        ind.push({i+(2*r), (mid-(currpow[i]+relevant))});
                        relevant = relevant + mid-(currpow[i]+relevant);
                        pows[i] = mid;
                    }
                }
                else pows[i] = currpow[i];
                if(!ind.empty())
                {
                    pair<long long int, long long int> temp = ind.front();
                    if(temp.first == i)
                    {
                        ind.pop();
                        relevant = relevant - temp.second;
                    }
                }
            }
            //if(mid == 118) { for(int i=0; i<n; i++) cout << rel[i] << " " ; cout << endl;}
            if(check) {maxx = max(maxx, mid); st = mid + 1;}
            else end = mid-1;
        }
        return maxx;
    }
};