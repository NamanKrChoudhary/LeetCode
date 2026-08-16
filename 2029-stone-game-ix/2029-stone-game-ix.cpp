class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        long long int cnt1=0, cnt2=0, cnt0=0;
        long long int n = stones.size();
        for(int i=0; i<n; i++) 
        {
            if(stones[i]%3 == 0) cnt0 = cnt0 + 1;
            else if(stones[i]%3 == 1) cnt1 = cnt1 + 1;
            else cnt2 = cnt2 + 1;
        }
        if(n == 1) return false;
        cout << cnt1 << " " << cnt2 << " " << cnt0 << endl;
        if((cnt1 == 0 && cnt2 == 0) || (cnt2 == 0 && cnt0 == 0) || (cnt1 == 0 && cnt0 == 0)) return false;
        if((cnt1 != 0 && cnt0 != 0 && cnt2 == 0) || (cnt2 != 0 && cnt0 != 0 && cnt1 == 0))
        {
            if(cnt1+cnt2 < 3 || cnt0%2 == 0) return false;
            else return true;
        }
        if(cnt1 != 0 && cnt2 != 0 && cnt0 == 0)
        {
            return true;
        }
        if(cnt0%2 == 1 && ((abs(cnt1-cnt2) <= 2) || (cnt1 == cnt2))) return false;
        return true;
    }
};