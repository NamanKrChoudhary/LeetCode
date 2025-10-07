class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> dry(n, -1), surrogate;
        set<int> curr;
        map<int, int> lakes;
        for(int i=0; i<n; i++)
        {
            if(rains[i] == 0) curr.insert(i);
            else
            {
                if(lakes.find(rains[i]) != lakes.end())
                {
                    int reqi = lakes[rains[i]];
                    if(curr.lower_bound(reqi) == curr.end()) return surrogate;
                    int ind = *curr.lower_bound(reqi);
                    dry[ind] = rains[i];
                    dry[i] = -1;
                    //cout << i << " " << rains[i] << " " << reqi << " " << ind << endl;
                    lakes[rains[i]] = i;
                    curr.erase(ind);
                }
                else
                {
                    lakes[rains[i]] = i;
                }
            }
        }
        int avl = 1;
        for(int i=0; i<n; i++) if(rains[i] > 0) {avl = rains[i]; break;}
        for(int i=0; i<n; i++)
        {
            if(rains[i] == 0 && dry[i] == -1) dry[i] = avl;
        }
        return dry;
    }
};