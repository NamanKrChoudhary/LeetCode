class Solution {
public:
    int minDifference(vector<int>& nums) {
        long long int n = nums.size();
        long long int cnt = 0;
        for(int i=0; i<n; i++) if(nums[i] == -1) cnt = cnt + 1;
        long long int st = 0, end = 1e9, mid = st + ((end-st)/2);
        long long int reqdiff = 1e9+5;
        vector<bool> vis(n, 0);
        vector<long long int> arr(n);
        for(int i=0; i<n; i++) arr[i] = nums[i];
        for(int i=1; i<arr.size(); i++) if(arr[i] != -1 && arr[i-1] != -1) st = max(st, abs(arr[i]-arr[i-1]));
        if(cnt == 0) return st;
        for(int i=1; i<n; i++) if(arr[i] == -1 && arr[i-1] == -1) vis[i] = true;
        while(st <= end)
        {
            mid = st + ((end-st)/2);
            bool check = true;
            vector<pair<long long int, long long int>> range(n, {-(1e9+5), (1e9+5)});
            //cout << mid << endl;
            for(int i=1; i<n; i++)
            {
                if(arr[i] == -1 && arr[i-1] == -1) range[i] = range[i-1];
                else if(arr[i] == -1) range[i] = {arr[i-1]-mid, arr[i-1]+mid};
                else if(arr[i-1] == -1 && vis[i-1] == true) range[i-1] = {arr[i]-mid, arr[i]+mid};
                else if(arr[i-1] == -1 && vis[i-1] == false) 
                {
                    pair<long long int, long long int> curr = {arr[i]-mid, arr[i]+mid};
                    //cout << i-1 << " " << range[i-1].first << " " << range[i-1].second << "      " << curr.first << " " << curr.second << endl;
                    if(range[i-1].second < curr.first || curr.second < range[i-1].first) {check = false; break;}
                    range[i-1] = {max(range[i-1].first, curr.first), min(range[i-1].second, curr.second)};
                }
            }
            //cout << mid << " " << check << endl << range[1].first << " " << range[1].second << "    " << range[2].first << " " << range[2].second << endl;
            if(check == false) {st = mid + 1; continue;}
            vector<pair<long long int, long long int>> finrange;
            for(int i=0; i<n; i++) if(range[i].first != -(1e9+5) && range[i].second != (1e9+5)) finrange.push_back(range[i]);
            sort(finrange.begin(), finrange.end());
            vector<pair<long long int, long long int>> reqrange;
            pair<long long int, long long int> curr = {-(1e9+5), (1e9+5)};
            //cout << "here" << endl;
            for(int i=0; i<finrange.size(); i++)
            {
                if(curr.second < finrange[i].first || finrange[i].second < curr.first)
                {
                    reqrange.push_back(curr);
                    curr = finrange[i];
                    continue;
                }
                curr.first = max(curr.first, finrange[i].first);
                curr.second = min(curr.second, finrange[i].second);
            }
            reqrange.push_back(curr);
            //cout << mid << " " << reqrange.size() << endl;
            if(reqrange.size() <= 1)
            {
                reqdiff = min(reqdiff, mid);
                end = mid-1;
            }
            else if(reqrange.size() == 2)
            {
                //cout << mid << endl << reqrange[0].first << " " << reqrange[0].second << "   " << reqrange[1].first << " " << reqrange[1].second << endl;
                long long int a = reqrange[0].first, b= reqrange[1].first;
                if(reqrange[0].second < reqrange[1].first) {a = reqrange[0].second; b = reqrange[1].first;}
                else if(reqrange[1].second < reqrange[0].first) {a = reqrange[1].second; b = reqrange[0].first;}
                else
                {
                    if(abs(reqrange[0].first - reqrange[1].first) < abs(reqrange[0].second - reqrange[1].second)) {a = reqrange[0].first; b = reqrange[1].first;}
                    else {a = reqrange[0].second; b = reqrange[1].second;}
                }
                if(abs(a-b) <= mid) {reqdiff = min(reqdiff, mid); end = mid-1; continue;}
                //cout << a << " " << b << endl;
                vector<pair<long long int, long long int>> segment;
                pair<long long int, long long int> ones = {LLONG_MAX, LLONG_MAX};
                for(int i=1; i<n; i++)
                {
                    if(arr[i] == -1 && arr[i-1] != -1) {ones.first = i-1;}
                    else if(arr[i] != -1 && arr[i-1] == -1 && ones.first != LLONG_MAX)
                    {
                        ones.second = i;
                        segment.push_back(ones);
                        ones = {LLONG_MAX, LLONG_MAX};
                    }
                }
                for(int i=0; i<segment.size(); i++)
                {
                    if(abs(a-arr[segment[i].first]) <= mid && abs(a-arr[segment[i].second]) <= mid) continue;
                    else if(abs(b-arr[segment[i].first]) <= mid && abs(b-arr[segment[i].second]) <= mid) continue;
                    else if (abs(a-b) <= mid) continue;
                    else {check = false; break;}
                }
                if(check == false) {st = mid + 1; continue;}
                else
                {
                    reqdiff = min(reqdiff, mid);
                    end = end - 1;
                }
            }
            else st = mid + 1;
        }
        return reqdiff;
    }
};