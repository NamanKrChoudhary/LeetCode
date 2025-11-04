class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        long long int n = nums.size();
        map<long long int, long long int> mp;
        for(int i=0; i<k; i++) mp[nums[i]]++;
        set<pair<long long int, long long int>> s1, s2;
        for(auto i: mp) s1.insert({i.second, i.first});
        int ssize = s1.size();
        for(int i=0; i<(ssize-x); i++)
        {
            pair<long long int, long long int> curr = *s1.begin();
            s1.erase(curr);
            s2.insert(curr);
        } 
        vector<long long int> sumarr(n-k+1);
        long long int currsum = 0;
        for(auto i: s1) currsum = currsum + (i.first*i.second);
        sumarr[0] = currsum;
        for(int i=0, j=k, l=1; l<sumarr.size()&&j<nums.size(); i++, j++, l++)
        {
            if(s1.find({mp[nums[i]], nums[i]}) != s1.end())
            {
                s1.erase({mp[nums[i]], nums[i]});
                currsum = currsum - (mp[nums[i]]*nums[i]);
            }
            else s2.erase({mp[nums[i]], nums[i]});
            mp[nums[i]]--;
            pair<long long int, long long int> curr1 = {mp[nums[i]], nums[i]};
            if(mp.find(nums[j]) != mp.end())
            {
                if(s1.find({mp[nums[j]], nums[j]}) != s1.end()) 
                {
                    s1.erase({mp[nums[j]], nums[j]});
                    currsum = currsum - (mp[nums[j]]*nums[j]);
                }
                else s2.erase({mp[nums[j]], nums[j]});
            }
            mp[nums[j]]++;
            pair<long long int, long long int> curr2 = {mp[nums[j]], nums[j]};
            s2.insert(curr2);
            if(curr1.second != curr2.second) s2.insert(curr1);
            // cout << "s1" << endl;
            // for(auto i: s1) cout << i.second << " " << i.first << endl;
            // cout << "s2" << endl;
            // for(auto i: s2) cout << i.second << " " << i.first << endl;
            // cout << endl;
            while(s1.size() < x && !s2.empty())
            {
                pair<long long int, long long int> temp = *s2.rbegin();
                currsum = currsum + (temp.first*temp.second);
                s1.insert(temp);
                s2.erase(temp);
            }
            while(!s2.empty() && (*s1.begin())<(*s2.rbegin()))
            {
                pair<long long int, long long int> temp1 = *s1.begin(), temp2 = *s2.rbegin();
                currsum = currsum - (temp1.first*temp1.second);
                s1.erase(temp1); s2.insert(temp1);
                currsum = currsum + (temp2.first*temp2.second);
                s2.erase(temp2); s1.insert(temp2);
            }
            //cout << i << " " << j << " " << l << endl;
            sumarr[l] = currsum;
        }
        return sumarr;
    }
};