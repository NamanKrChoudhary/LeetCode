class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = n/2, j = n-1;
        if(n%2 == 0) i = i-1;
        long long int cnt = 0;
        vector<bool> vis(n,false);
        //for(int i=0; i<n; i++) cout << nums[i] << " "; cout << endl;
        while(i>=0 && j>=0)
        {
            if(vis[j]) {j = j-1; continue;}
            if(i>=j) {i = j-1; continue;}
            if(2*nums[i] <= nums[j]) 
            {
                cnt = cnt + 2; 
                vis[i] = true;
                vis[j] = true;
                i = i-1; 
                j = j-1;
            }
            else if(2*nums[i] > nums[j]) i = i-1;
        }
        return cnt;
    }
};