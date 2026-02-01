class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long int n = nums.size();
        multiset<long long int> less, great;
        long long int req = nums[0];
        long long int lsum = 0, gsum = 0;
        for(int i=1; i<k; i++) 
        {
            less.insert(nums[i]); 
            lsum = lsum + nums[i];
        }
        long long int minn = lsum;
        for(int i=k; i<n; i++)
        {
            if(i > dist+1)
            {
                long long int ind = i-dist-1;
                if(!great.empty() && great.find(nums[ind]) != great.end())
                {
                    auto it = great.find(nums[ind]);
                    great.erase(it);
                }
                else
                {
                    auto it = less.find(nums[ind]);
                    less.erase(it);
                    lsum = lsum - nums[ind];
                    if(!great.empty()) 
                    {
                        long long int beg = 0;
                        beg = *great.begin();
                        auto it1 = great.find(beg);
                        great.erase(it1);
                        less.insert(beg);
                        lsum = lsum + beg;
                    }
                }
            }
            lsum = lsum + nums[i];
            less.insert(nums[i]);
            if(less.size() > k-1)
            {
                long long int temp = *less.rbegin();
                lsum = lsum - temp;
                auto it = less.find(temp);
                less.erase(it);
                great.insert(temp);
            }
            minn = min(lsum, minn);
            //cout << i << " " << lsum << endl;
        }
        return minn+req;
    }
};