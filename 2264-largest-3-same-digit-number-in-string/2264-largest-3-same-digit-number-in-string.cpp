class Solution {
public:
    string largestGoodInteger(string num) {
        set<int> s;
        for(int i=2; i<num.size(); i++)
        {
            if(num[i-2] == num[i-1] && num[i-1] == num[i]) s.insert(num[i]-'0');
        }
        string lsd = "";
        int maxx = -1;
        for(auto i: s) maxx = max(maxx, i);
        if(maxx != -1) for(int i=0; i<3; i++) lsd.push_back('0'+maxx);
        return lsd;
    }
};