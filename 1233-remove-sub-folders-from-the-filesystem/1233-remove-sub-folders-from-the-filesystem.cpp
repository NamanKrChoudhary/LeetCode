class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> arr = folder;
        sort(arr.begin(), arr.end());
        vector<string> just;
        for(int i=0; i<arr.size(); i++)
        {
            if(just.empty()) {just.push_back(arr[i]);}
            else
            {
                string prev = just[just.size()-1];
                string curr = arr[i];
                if(prev.size() >= curr.size() && prev != curr) just.push_back(curr);
                else
                {
                    bool check = true;
                    for(int j=0; j<prev.size(); j++) if(curr[j] != prev[j]) {check = false; break;}
                    if(check && curr[prev.size()] != '/') check = false;
                    if(!check) just.push_back(curr);
                }
            }
        }
        return just;
    }
};