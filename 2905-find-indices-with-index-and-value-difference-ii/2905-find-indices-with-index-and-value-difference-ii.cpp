class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        long long int indiff = indexDifference, valdiff = valueDifference;
        set<pair<long long int, long long int>> s;
        vector<int> ans(2); ans[0]=-1; ans[1]=-1;
        long long int n = nums.size();
        for(int i = indiff; i<nums.size(); i++)
        {
            pair<long long int, long long int> p;
            p.first = nums[i]; p.second = i;
            s.insert(p);
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(i+indiff-1 <= n-1 && i+indiff-1 >= 0)
            {
                pair<long long int, long long int>p = {nums[i+indiff-1], i+indiff-1};
                if(s.find(p) != s.end())s.erase(p);
            }
            cout << i << " " << s.size() << endl;
            if(s.empty()) break;
            auto it1 = s.end(); it1--;
            auto it2 = s.begin();
            pair<long long int, long long int>p1 = *it1, p2 = *it2;
            long long int req1 =(abs(nums[i]-p1.first));
            long long int req2 =(abs(nums[i]-p2.first));
            long long int req,reqi;
            if(req1 > req2) {req = req1; reqi = p1.second;}
            else {req = req2; reqi = p2.second;}
            if(req >= valdiff) {ans[0] = i; ans[1]= reqi; break;}
        }
        return ans;
    }
};