class Solution {
public:
    bool checker(map<string, vector<char>>& pattern, vector<string>& arr, long long int curri, long long int currj, long long int n, map<string, bool>& prev)
    {
        if(curri >= n) return true;
        string curr = "";
        curr.push_back(arr[curri-1][currj]);
        curr.push_back(arr[curri-1][currj+1]);
        if(pattern.find(curr) != pattern.end())
        {
            for(int tempi = 0; tempi < pattern[curr].size(); tempi++)
            {
                arr[curri][currj] = pattern[curr][tempi];
                bool check = false;
                if(currj < n-curri-1) check = checker(pattern, arr, curri, currj+1, n, prev);
                else 
                {
                    if(prev.find(arr[curri]) != prev.end()) check = prev[arr[curri]];
                    else 
                    {
                        check = checker(pattern, arr, curri+1, 0, n, prev);
                        prev[arr[curri]] = check;
                    }
                }
                if(check) return true;
                arr[curri][currj] = '#';
            }
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<string, vector<char>> pattern;
        for(int i=0; i<allowed.size(); i++)
        {
            string curr = "";
            curr.push_back(allowed[i][0]);
            curr.push_back(allowed[i][1]);
            pattern[curr].push_back(allowed[i][2]);
        }
        map<string, bool> prev;
        vector<string> arr(bottom.size());
        for(int i=0; i<bottom.size(); i++) arr[0][i] = bottom[i];
        for(int i=1; i<bottom.size()-1; i++) for(int j=0; j<bottom.size()-i; j++) arr[i].push_back('#');
        //for(int i=0; i<arr.size(); i++) {for(int j=0; j<arr[i].size(); j++) cout << arr[i][j] << " "; cout << endl;}
        return checker(pattern, arr, 1, 0, bottom.size(), prev);
    }
};