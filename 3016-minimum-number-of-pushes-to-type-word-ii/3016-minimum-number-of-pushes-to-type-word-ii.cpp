class Solution {
public:
    int minimumPushes(string word) {
        map<char, long long int> mp;
        for(int i=0; i<word.size(); i++) mp[word[i]]++;
        deque<long long int> avl = {4,4};
        for(int i=2; i<=9; i++)
        {
            avl.push_back(1);
            avl.push_back(2);
            avl.push_back(3);
        }
        sort(avl.begin(), avl.end());
        vector<long long int> chars;
        for(auto i: mp) chars.push_back(i.second);
        sort(chars.rbegin(), chars.rend());
        long long int req = 0;
        for(auto i: chars)
        {
            //cout << i << " " << avl[0] << endl;
            req = req + (avl[0]*i);
            avl.pop_front();
        }
        return req;
    }
};