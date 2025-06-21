class Solution {
public:
    int minimumDeletions(string word, int k) {
        long long int n = word.size();
        map<char, long long int> mp;
        for(int i=0; i<word.size(); i++) mp[word[i]]++;
        vector<long long int> arr;
        for(auto i: mp) arr.push_back(i.second);
        sort(arr.begin(), arr.end());
        long long int tot = word.size();
        vector<long long int> pref(arr.size());
        pref[0] = arr[0]; 
        for(int i=1; i<arr.size(); i++) pref[i] = arr[i] + pref[i-1];
        for(int i=0; i<arr.size(); i++)
        {  
            long long int next = upper_bound(arr.begin(), arr.end(), arr[i]+k) - arr.begin();
            long long int bef = pref[i]-arr[i];
            long long int aft = 0;
            if(next < arr.size()) aft = (pref[arr.size()-1]-pref[next]+arr[next]) - ((arr.size()-next)*(arr[i]+k));
            tot = min(tot, bef+aft);
        }
        return tot;
    }
};