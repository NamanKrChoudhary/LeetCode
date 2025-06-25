class Solution {
public:

    const long long int ZZEERROO = 0;

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long int least = -1e10, greatest = 1e10, kth = least + (greatest - least)/2;
        vector<long long int> neg2(nums2.size());
        for(int i=0; i<nums2.size(); i++) neg2[i] = (-1)*nums2[nums2.size()-1-i];
        long long int minn = 1LL*nums1[0]*nums2[0];;
        while(least <= greatest)
        {
            kth = least + (greatest - least)/2;
            long long int cntless = 0;
            bool have = false;
            long long int pos = 1e10;
            for(int i=0; i<nums1.size(); i++)
            {
                if(nums1[i] == 0 && kth >= 0) {cntless = cntless + nums2.size(); if(0>=kth)pos = min(pos, ZZEERROO); continue;}
                else if(nums1[i] == 0) continue;
                if(kth >= 0)
                {
                    if(nums1[i] >= 0)
                    {
                        long long int req = kth/nums1[i];
                        if(kth%nums1[i] != 0) req = req;
                        long long int cnt = upper_bound(nums2.begin(), nums2.end(), req) - nums2.begin();
                        long long int have = lower_bound(nums2.begin(), nums2.end(), req) - nums2.begin();
                        long long int currpos = pos;
                        if(have < nums2.size()) currpos = (1LL*nums1[i]*nums2[have]);
                        if(have < nums2.size() && currpos >= kth) pos = min(pos, currpos);
                        cntless = cntless + cnt;
                    }
                    else
                    {
                        long long int req = (-1)*(kth/nums1[i]);
                        if(kth%nums1[i] != 0) req = req ;
                        long long int cnt = upper_bound(neg2.begin(), neg2.end(), req) - neg2.begin();
                        long long int have = lower_bound(neg2.begin(), neg2.end(), req) - neg2.begin();
                        long long int currpos = pos;
                        if(have < nums2.size()) currpos = (1LL*nums1[i]*neg2[have]*(-1));
                        if(have < nums2.size() && currpos >= kth)pos = min(pos, currpos);
                        cntless = cntless + cnt;
                    }
                }
                else
                {
                    if(nums1[i] >= 0)
                    {
                        long long int req = kth/nums1[i];
                        if(kth%nums1[i] != 0) req = req - 1;
                        long long int cnt = upper_bound(nums2.begin(), nums2.end(), req) - nums2.begin();
                        long long int have = lower_bound(nums2.begin(), nums2.end(), req) - nums2.begin();
                        long long int currpos = pos;
                        if(have < nums2.size()) currpos = (1LL*nums1[i]*nums2[have]);
                        if(have < nums2.size() && currpos >= kth) pos = min(pos, currpos);
                        cntless = cntless + cnt;
                    }
                    else
                    {
                        long long int req = (-1)*(kth/nums1[i]);
                        if(kth%nums1[i] != 0) req = req - 1;
                        long long int cnt = upper_bound(neg2.begin(), neg2.end(), req) - neg2.begin();
                        long long int have = lower_bound(neg2.begin(), neg2.end(), req) - neg2.begin();
                        long long int currpos = pos;
                        if(have < nums2.size()) currpos = (1LL*nums1[i]*neg2[have]*(-1));
                        if(have < nums2.size() && currpos >= kth) pos = min(pos,currpos);
                        cntless = cntless + cnt;
                    }
                }
                //if(kth == 9)cout << i << " " << cntless << endl;
            }
            //cout << least << " " << greatest << " " << kth << " " << cntless << endl;
            if(cntless >= k)
            {
                //cout << kth << " " << pos << " " << cntless << endl;
                minn = pos;
                greatest = kth-1;
            }
            else least = kth + 1;
        }
        return minn;
    }
};