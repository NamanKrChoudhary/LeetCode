class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> prev = nums;
        for(int k=1; k<nums.size(); k++)
        {
            //for(int i=0; i<prev.size(); i++) cout << prev[i] << " "; cout << endl;
            vector<int> curr;
            for(int i=1; i<prev.size(); i++) 
            {
                curr.push_back((prev[i-1]+prev[i])%10);
            }
            prev = curr;
        }
        return prev[0];
    }
};