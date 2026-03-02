#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<
                        T, 
                        null_type,
                        less<T>,
                        rb_tree_tag,
                        tree_order_statistics_node_update
                        >;
class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        long long int curr = 0;
        ordered_set<pair<long long int, long long int>> s;
        map<long long int, long long int> mp;
        for(int i=0; i<k; i++) 
        {
            long long int smaller = s.order_of_key({nums[i],i});
            curr = curr + (s.size()-smaller);
            s.insert({nums[i], i});
            mp[nums[i]]++;
        }
        long long int minn = curr;
        for(int i=k; i<nums.size(); i++)
        {
            long long int smaller1 = s.order_of_key({nums[i-k],i-k});
            mp[nums[i-k]]--;
            s.erase({nums[i-k], i-k});
            curr = curr - smaller1;
            long long int smaller2 = s.order_of_key({nums[i], i});
            curr = curr + (s.size()-smaller2);
            s.insert({nums[i], i});
            mp[nums[i]]++;
            minn = min(minn, curr);
        }
        return minn;
    }
};