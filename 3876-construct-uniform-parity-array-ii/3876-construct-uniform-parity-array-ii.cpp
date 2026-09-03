class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        long long int n = nums1.size();
        bool checkodd = false;
        sort(nums1.begin(), nums1.end());
        vector<vector<bool>> arr(n, vector<bool>(2, false));
        for(int i=0; i<n; i++)
        {
            if(nums1[i]%2 == 0)
            {
                arr[i][0] = true;
                if(checkodd == true) arr[i][1] = true;
            }
            else
            {
                arr[i][1] = true;
                if(checkodd == true) arr[i][0] = true;
                checkodd = true;
            }
        }
        bool check1 = true, check2 = true;
        for(int i=0; i<n; i++)
        {
            check1 = check1&arr[i][0];
            check2 = check2&arr[i][1];
        }
        return (check1 | check2);
    }
};