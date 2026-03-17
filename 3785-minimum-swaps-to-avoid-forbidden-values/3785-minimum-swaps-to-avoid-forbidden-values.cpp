class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        long long int n = nums.size();
        map<long long int, long long int> mp;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == forbidden[i]) mp[nums[i]]++;
        }
        long long int total = 0, maxx = 0, maxxi = -1;
        for(auto i: mp) 
        {
            total = total + i.second;
            if(maxx < i.second){maxx = i.second; maxxi = i.first;}
        }
        long long int req = 0;
        if(maxx > total/2)
        {
            long long int extra = 0;
            for(int i=0; i<n; i++) if(nums[i] != maxxi && forbidden[i] != maxxi && nums[i] != forbidden[i]) extra = extra + 1;
            if(extra >= maxx - (total-maxx)) req = maxx;
            else req = -1;
        }
        else
        {
            if(total%2 == 0) req = total/2;
            else req = (total/2)+1;
        }
        return req;
    }
};