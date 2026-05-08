class Solution {
public:
    int minJumps(vector<int>& nums) {
        long long int n = nums.size();
        long long int maxx = -1;
        for(int i=0; i<n; i++) maxx = max(maxx, static_cast<long long int>(nums[i]));
        vector<long long int> spf(maxx+1, -1); 
        spf[0] = 0; spf[1] = 1;
        //cout << spf[2] << endl;
        for(long long int i=2; i<=maxx; i++)
        {
            if(spf[i] == -1)
            {
                //cout << i << endl;
                spf[i] = i;
                for(long long int j=i*i; j<=maxx; j=j+i)
                {
                    if(spf[j] == -1) spf[j] = i;
                }
            }
        }
        //cout << spf[2] << endl;
        map<long long int, vector<long long int>> primes;
        for(int i=0; i<n; i++)
        {
            long long int temp = nums[i];
            while(temp > 1)
            {
                long long int pf = spf[temp];
                //cout << i << " " << pf << endl;
                primes[pf].push_back(i);
                while(temp%pf == 0) temp = temp/pf;
            }
        }
        priority_queue<pair<long long int,long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
        pq.push({0,0});
        vector<long long int> steps(n, -1);
        long long int req = 0;
        map<long long int, bool> propogate;
        while(!pq.empty())
        {
            pair<long long int, long long int> curr = pq.top();
            pq.pop();
            long long int currsteps = curr.first;
            long long int currind = curr.second;
            if(currind == n-1) {req = currsteps; break;} 
            //if(steps[currind] != -1) continue;
            //steps[currind] = currsteps+1;
            if(currind-1 >= 0 && steps[currind-1] == -1) 
            {
                pq.push({currsteps+1, currind-1});
                steps[currind-1] = currsteps+1;
            }
            if(currind+1 < n && steps[currind+1] == -1) 
            {
                pq.push({currsteps+1, currind+1});
                steps[currind+1] = currsteps+1;
            }
            if(spf[nums[currind]] == nums[currind] && propogate.find(nums[currind]) == propogate.end())
            {
                propogate[nums[currind]] = true;
                for(int i=0; i<primes[nums[currind]].size(); i++)
                {
                    if(steps[primes[nums[currind]][i]] == -1) 
                    {
                        pq.push({currsteps+1, primes[nums[currind]][i]});
                        steps[primes[nums[currind]][i]] = currsteps+1;
                    }
                }
            }
        }
        return req;
    }
};