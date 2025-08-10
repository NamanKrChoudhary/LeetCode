vector<vector<long long int>> tp;

void filler(vector<vector<long long int>>& tp)
{
    long long int curr = 1; tp.push_back({1});
    while(curr <= 1e9)
    {
        curr = curr*2;
        vector<long long int> temp;
        long long int tempnum = curr;
        while(tempnum)
        {
            temp.push_back(tempnum%10);
            tempnum = tempnum/10;
        }
        sort(temp.begin(), temp.end());
        tp.push_back(temp);
    }
}

class Solution {
public:
    Solution() {filler(tp);}
    bool reorderedPowerOf2(int n) {
        vector<long long int> curr;
        long long int temp = n;
        while(temp)
        {
            curr.push_back(temp%10);
            temp = temp/10;
        }
        sort(curr.begin(), curr.end());
        for(int i=0; i<tp.size(); i++)
        {
            if(curr == tp[i]) return true;
        }
        return false;
    }
};