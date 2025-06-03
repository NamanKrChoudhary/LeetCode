class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
       long long int n = status.size();
        vector<bool> boxfound(n, 0), keysfound(n, 0);
        for(int i=0; i<n; i++) if(status[i]) keysfound[i] = true;
        for(int i=0; i<initialBoxes.size(); i++) boxfound[initialBoxes[i]] = true;
        queue<long long int> q;
        vector<bool> boxvis(n,0);
        for(int i=0; i<n; i++)
        {
            if(keysfound[i] == true && boxfound[i] == true) {q.push(i); boxvis[i] = true;}
        }
        long long int ans = 0;
        while(!q.empty())
        {
            long long int currbox = q.front();
            q.pop(); 
            ans = ans + candies[currbox];
            for(int i=0; i<containedBoxes[currbox].size(); i++)
            {
                boxfound[containedBoxes[currbox][i]] = true;
                if(!boxvis[containedBoxes[currbox][i]] == true && keysfound[containedBoxes[currbox][i]] == true) {boxvis[containedBoxes[currbox][i]] = true; q.push(containedBoxes[currbox][i]);}
            }
            for(int i=0; i<keys[currbox].size(); i++)
            {
                long long int currkey = keys[currbox][i];
                keysfound[currkey] = true;
                if(!boxvis[currkey] == true && boxfound[currkey] == true) {boxvis[currkey] = true; q.push(currkey);}
            }
        }
        return ans;
    }
};