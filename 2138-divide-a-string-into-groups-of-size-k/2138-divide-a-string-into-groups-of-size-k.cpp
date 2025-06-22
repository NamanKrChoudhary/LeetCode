class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        long long int n = s.size();
        vector<string> arr;
        string temp = "";
        for(int i=0; i<n; i++)
        {
            if(i == 0) {temp.push_back(s[i]); continue;}
            else if(i%k == 0) {arr.push_back(temp); temp = ""; temp.push_back(s[i]); continue;}
            else temp.push_back(s[i]);
        }
        while(temp.size() < k)
        {
            temp.push_back(fill);
        }
        arr.push_back(temp);
        return arr;
    }
};