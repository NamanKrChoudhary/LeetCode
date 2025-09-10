class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        long long int minn = INT_MAX;
        vector<set<long long int>> lang(languages.size());
        for(int i=0; i<languages.size(); i++)
        {
            for(auto j: languages[i]) lang[i].insert(j);
        }
        for(int i=1; i<=n; i++)
        {
            map<long long int, bool> has;
            for(int j=0; j<languages.size(); j++)
            {
                if(lang[j].count(i)) has[j] = true;
            }
            long long int changes = 0;
            for(int j=0; j<friendships.size(); j++)
            {
                bool check = false;
                for(auto k: languages[friendships[j][0]-1])
                {
                    if(lang[friendships[j][1]-1].count(k)) {check = true; break;}
                }
                if(check == false)
                {
                    if(has.find(friendships[j][0]-1) == has.end())
                    {
                        has[friendships[j][0]-1] = true;
                        changes = changes+1;
                    }
                    if(has.find(friendships[j][1]-1) == has.end())
                    {
                        has[friendships[j][1]-1] = true;
                        changes = changes + 1;
                    }
                }
            }
            minn = min(minn, changes);
        }
        return minn;
    }
};