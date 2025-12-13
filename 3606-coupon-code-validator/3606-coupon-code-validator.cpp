class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string, string> mp;
        mp["electronics"] = "0";
        mp["grocery"] = "1";
        mp["pharmacy"] = "2";
        mp["restaurant"] = "3";
        vector<pair<string, string>> arr;
        for(int i=0; i<code.size(); i++)
        {
            bool check = true;
            for(int j=0; j<code[i].size(); j++)
            {
                if(code[i][j] == '_') continue;
                else if(code[i][j]-'a' >= 0 && code[i][j]-'a' < 26) continue;
                else if(code[i][j]-'A' >=0 && code[i][j]-'A' < 26) continue;
                else if(code[i][j]-'0' >= 0 && code[i][j]-'0' < 10) continue;
                else {check = false; break;}
            }
            if(code[i] == "") check = false;
            if(mp.find(businessLine[i]) == mp.end()) check = false;
            if(isActive[i] == true && check == true)
            {
                arr.push_back({mp[businessLine[i]], code[i]});
            }
        }
        sort(arr.begin(), arr.end());
        //for(auto i: arr) cout << i.first << " " << i.second << endl;
        vector<string> req;
        for(int i=0; i<arr.size(); i++) req.push_back(arr[i].second);
        return req;
    }
};