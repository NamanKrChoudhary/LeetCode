class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        vector<long long int> spf(1e5+1, -1);
        for(long long int i=2; i<=1e5; i++)
        {
            if(spf[i] == -1)
            {
                spf[i] = i;
                for(long long int j = i*i; j<=1e5; j=j+i) if(spf[j] == -1) spf[j] = i;
            }
        }
        long long int n = nums.size();
        long long int req = 0;
        for(int i=0; i<n; i++)
        {
            long long int temp = nums[i];
            map<long long int, long long int> div;
            bool check = true;
            while(temp > 1)
            {
                long long int currdiv = spf[temp];
                long long int cnt = 0;
                while(temp%currdiv == 0)
                {
                    cnt = cnt + 1;
                    temp = temp/currdiv;
                    if(cnt > 1) break;
                }
                if(cnt > 1) {check = false; break;}
                div[currdiv] = 1;
            }
            if(div.size() != 2 || check == false) continue;
            else 
            {
                req = req + 1 + nums[i];
                for(auto j: div) req = req + j.first;
            }
        }
        return req;
    }
};