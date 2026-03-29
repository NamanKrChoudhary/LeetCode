class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        long long int n = s1.size();
        vector<char> odd1, odd2, eve1, eve2;
        for(int i=0; i<n; i++)
        {
            if(i%2 == 0) 
            {
                eve1.push_back(s1[i]);
                eve2.push_back(s2[i]);
            }
            else
            {
                odd1.push_back(s1[i]);
                odd2.push_back(s2[i]);
            }
        }
        sort(eve1.begin(), eve1.end());
        sort(odd1.begin(), odd1.end());
        sort(eve2.begin(), eve2.end());
        sort(odd2.begin(), odd2.end());
        if(odd1 == odd2 && eve1 == eve2) return true;
        else return false;
    }
};