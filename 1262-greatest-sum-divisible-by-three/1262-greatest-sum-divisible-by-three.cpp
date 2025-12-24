class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        long long int n = nums.size();
        vector<long long int> a,b,c;
        for(int i=0; i<n; i++)
        {
            if(nums[i]%3 == 0) a.push_back(nums[i]);
            else if(nums[i]%3 == 1) b.push_back(nums[i]);
            else c.push_back(nums[i]);
        }
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        sort(c.rbegin(), c.rend());
        long long int req = 0;
        for(int i=0; i<a.size(); i++) req = req + a[i];
        for(int i=2; i<b.size(); i=i+3) req = req + b[i]+b[i-1]+b[i-2];
        for(int i=2; i<c.size(); i=i+3) req = req + c[i]+c[i-1]+c[i-2];
        //cout << req << endl;
        if(b.size()%3 == 1 && c.size()%3 == 1) req = req + b[b.size()-1] + c[c.size()-1];
        if(b.size()%3 == 2 && c.size()%3 == 2) req = req + b[b.size()-1] + b[b.size()-2] + c[c.size()-1] + c[c.size()-2];
        else if(b.size()%3 == 1 && c.size()%3 == 2) 
        {
            if(b.size() > 1 && c[c.size()-1] > b[b.size()-1]+b[b.size()-2]) 
            {
                //cout << "here" << endl;
                req = req + c[c.size()-2] - b[b.size()-2] + c[c.size()-1];
            }
            else req = req + b[b.size()-1] + c[c.size()-2];
        }
        else if(b.size()%3 == 2 && c.size()%3 == 1) 
        {
            //cout << "here" << endl;
            if(c.size() > 1 && b[b.size()-1] > c[c.size()-1]+c[c.size()-2]) 
            {
                req = req + b[b.size()-2] - c[c.size()-2] + b[b.size()-1];
                //cout << "here" << endl;
            }
            else req = req + b[b.size()-2] + c[c.size()-1];
        }
        else if(b.size()%3 == 0 && c.size()%3 == 2)
        {
            if(b.size() > 1 && c[c.size()-1]+c[c.size()-2] > b[b.size()-1])
            {
                req = req - b[b.size()-1] + c[c.size()-1] + c[c.size()-2];
            }
        }
        else if(b.size()%3 == 2 && c.size()%3 == 0)
        {
            if(c.size() > 1 && b[b.size()-1]+b[b.size()-2] > c[c.size()-1])
            {
                req = req - c[c.size()-1] + b[b.size()-1] + b[b.size()-2];
            }
        }
        else if(b.size()%3 == 0 && c.size()%3 == 1)
        {
            if(b.size() > 1 && b[b.size()-1]+b[b.size()-2] < c[c.size()-1])
            {
                req = req - b[b.size()-1] - b[b.size()-2] + c[c.size()-1];
            }
        }
        else if(b.size()%3 == 1 && c.size()%3 == 0)
        {
            if(c.size() > 1 && c[c.size()-1]+c[c.size()-2] < b[b.size()-1])
            {
                req = req - c[c.size()-1] - c[c.size()-2] + b[b.size()-1];
            }
        }
        return req;
    }
};