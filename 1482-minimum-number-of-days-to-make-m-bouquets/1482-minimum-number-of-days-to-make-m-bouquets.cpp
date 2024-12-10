class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int ans = -1;
        long long int s = 0, e = *max_element(bloomDay.begin(), bloomDay.end()), mid = s+((e-s)/2);
        while(s<=e)
        {
            mid = s+((e-s)/2);
            long long int divs = 0;
            long long int bou = 0;
            for(int i=0; i<bloomDay.size(); i++)
            {
                if(bloomDay[i] <= mid){divs = divs+1;}
                else {divs = 0;}
                if(divs>= k){divs = 0; bou = bou+1;}
            }
            if(bou>=m){ans = mid; e = mid-1;}
            else {s = mid+1;}
        }
        return ans;
    }
};