class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1) return true;
        vector<long long int> pref(nums.size());
        vector<long long int> vis(nums.size());
        long long int n = nums.size();
        for(int i=1; i<n; i++) 
        {
            if(nums[i] > nums[i-1]) {pref[i] = pref[i-1]+1; vis[i] = 1;}
            else {pref[i] = pref[i-1]; vis[i] = 0;}
        }
        for(int i=0; i<n; i++) cout << pref[i] << " "; cout << endl;
        long long int i=0,j=k, l = (2*k)-1;
        for(; i<n && j<n && l<n; i++, j++, k++)
        {
            long long int prevsum = pref[j-1]-pref[i]+vis[i];
            long long int postsum = pref[l]-pref[j]+vis[j];
            if(prevsum == k-1 && postsum == k-1) return true;
        }
        return false;
    }
};