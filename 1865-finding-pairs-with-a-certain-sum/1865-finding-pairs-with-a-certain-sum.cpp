class FindSumPairs {
public:
    multiset<long long int> temp1;
    multiset<long long int> temp2;
    vector<int> f;
    vector<int> s;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto i: nums1) temp1.insert(i);
        for(auto i: nums2) temp2.insert(i);
        f = nums1;
        s = nums2;
    }
    
    void add(int index, int val) {
        auto it = temp2.find(s[index]);
        temp2.erase(it);
        s[index] = s[index] + val;
        temp2.insert(s[index]);
    }
    
    int count(int tot) {
        long long int cnt = 0;
        for(int i=0; i<f.size(); i++)
        {
            auto it = temp2.count(tot-f[i]);
            cnt = cnt+it;
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */