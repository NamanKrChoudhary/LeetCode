class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        long long int n = nums.size();
        if(n == 2)
        {
            if(nums[0] == nums[1]) return 1;
            else return 0;
        }
        vector<long long int> prev(n), prev1(n), suf(n), suf1(n);
        int temp = 0;
        for(int i=0; i<n; i++) 
        {
            temp = __gcd(temp, nums[i]);
            prev[i] = temp;
        }
        temp = 0;
        for(int i=1; i<n; i++) 
        {
            temp =  __gcd(temp, nums[i]);
            prev1[i] = temp;
        }
        temp = 0;
        for(int i=n-1; i>=0; i--) 
        {
            temp = __gcd(temp, nums[i]);
            suf[i] = temp;
        }
        temp = 0;
        for(int i=n-2; i>=0; i--) 
        {
            temp = __gcd(temp, nums[i]);
            suf1[i] = temp;
        }
        long long int req = 0;
        long long int type1 = 0;
        for(int i=1; i<n; i++)
        {
            if(prev[i-1] == suf[i]) type1 = type1 + 1;
        }
        long long int type2 = 0;
        for(int i=2; i<n; i++)
        {
            if(prev1[i-1] == suf[i]) type2 = type2 + 1;
        }
        long long int type3 = 0;
        for(int i=1; i<n-1; i++)
        {
            if(prev[i-1] == suf1[i]) type3 = type3 + 1;
        }
        long long int type4 = 0;
        if(type1 == 0)
        {
            long long int ind = -1;
            for(int i=2; i<n; i++)
            {
                // cout << i << endl;
                // cout << prev[i-2] << " " << suf[i] << endl;
                if(prev[i-2] > suf[i-1] && prev[i-1] < suf[i]) {ind = i-1; break;}
            }
            //cout << ind << endl;
            if(ind != -1)
            {
                //cout << "here" << endl;
                vector<long long int> temparr;
                for(int i=0; i<n; i++) if(i != ind) temparr.push_back(nums[i]);
                vector<long long int> tempprev(n-1), tempsuf(n-1);
                long long int currtemp = 0;
                for(int i=0; i<temparr.size(); i++)
                {
                    currtemp = __gcd(currtemp, temparr[i]);
                    tempprev[i] = currtemp;
                }
                currtemp = 0;
                for(int i=temparr.size()-1; i>=0; i--) 
                {
                    currtemp = __gcd(currtemp, temparr[i]);
                    tempsuf[i] = currtemp;
                }
                for(int i=1; i<temparr.size(); i++)
                {
                    if(tempprev[i-1] == tempsuf[i]) type4 = type4+1;
                }
            }
        }
        //cout << type1 << " " << type2 << " " << type3 << " " << type4 << endl;
        long long int maxx = max(type1,type2);
        maxx = max(maxx, type3);
        maxx = max(maxx, type4);
        return maxx;
    }
};