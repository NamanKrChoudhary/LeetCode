class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for(int i=0; i<arr.size(); i++) mp[arr[i]]++;
        vector<int> curr;
        for(auto i: mp) curr.push_back(i.first);
        for(int i=0; i<curr.size(); i++) mp[curr[i]] = i;
        vector<int> req(arr.size());
        for(int i=0; i<arr.size(); i++) req[i] = mp[arr[i]] + 1;
        return req;
    }
};