class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        long long int req = 0, tot = 0, curr = 0;
        for(int i=0; i<apple.size(); i++) tot = tot + apple[i];
        sort(capacity.rbegin(), capacity.rend());
        for(int i=0; i<capacity.size(); i++)
        {
            curr = curr + capacity[i];
            req = req + 1;
            if(curr >= tot) break;
        }
        return req;
    }
};