class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, long long int> mp;
        for(int i=0; i<words.size(); i++)
        {
            mp[words[i]]++;
        }
        long long int a = 0, b = 0;
        bool check = false;
        for(auto i: mp)
        {
            if((i.first)[0] == i.first[1])
            {
                b = b+(4*(i.second/2));
                if(i.second%2 == 1) check = true;
            }
            else
            {
                string temp = "";
                temp.push_back((i.first)[1]);
                temp.push_back((i.first)[0]);
                if(mp.find(temp) != mp.end()) {a = a+(2*min(i.second, mp[temp]));}
                cout << temp << " " << a << endl;
            }
        }
        if(check) b = b+2;
        return (a+b);
    }
};