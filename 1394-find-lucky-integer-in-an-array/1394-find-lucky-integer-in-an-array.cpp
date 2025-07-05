class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<long long int, long long int> mp;
        for(int i=0; i<arr.size(); i++) mp[arr[i]]++;
        long long int check = -1;
        for(auto i: mp) if(i.second == i.first) check = max(check, i.first);
        return check;
    }
};