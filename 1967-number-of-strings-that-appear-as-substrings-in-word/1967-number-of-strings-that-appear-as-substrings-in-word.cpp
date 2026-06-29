class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        long long int req = 0;
        long long int n = word.size();
        multiset<string> s;
        for(int i=0; i<patterns.size(); i++) s.insert(patterns[i]);
        //long long int req = 0;
        long long int i = 0;
        while(i<n && !s.empty())
        {
            string temp = "";
            long long int j = i;
            while(j<n && !s.empty())
            {
                temp.push_back(word[j]);
                long long int curr = s.count(temp);
                if(curr > 0) 
                {
                    req = req + curr;
                    s.erase(temp);
                }   
                j = j+1;
            }
            i = i+1;
        }
        return req;
    }
};