class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        long long int n = nums.size();
        vector<vector<int>> arr(nums.size()/3, vector<int>(3));
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        bool check = false;
        for(int i=0, j=0; i<n && j<n/3; i = i+3, j = j+1)
        {
            if(temp[i+2] - temp[i] > k) {check = true; break;}
            arr[j][0] = temp[i];
            arr[j][1] = temp[i+1];
            arr[j][2] = temp[i+2]; 
        }
        vector<vector<int>> ans;
        if(check) return ans;
        for(int i=0; i<arr.size(); i++) ans.push_back(arr[i]);
        return ans;
    }
};