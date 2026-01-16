class Solution {
public:
    const long long int mod = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        set<long long int> reqLen;
        vector<long long int> length, width;
        long long int maxSize = -1;
        length.push_back(1); width.push_back(1);
        for(auto i: hFences) length.push_back(i);
        for(auto i: vFences) width.push_back(i);
        length.push_back(m); width.push_back(n);
        sort(length.begin(), length.end());
        sort(width.begin(), width.end());
        for(int i=0; i<length.size(); i++)
        {
            for(int j=i+1; j<length.size(); j++)
            {
                reqLen.insert(length[j]-length[i]);
            }
        }
        for(int i=0; i<width.size(); i++)
        {
            for(int j=i+1; j<width.size(); j++)
            {
                if(reqLen.find(width[j]-width[i]) != reqLen.end()) maxSize = max(maxSize, ((width[j]-width[i])*(width[j]-width[i])));
            }
        }
        return maxSize%mod;
    }
};