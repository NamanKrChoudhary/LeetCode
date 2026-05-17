class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        long long int n = arr.size();
        queue<long long int> q;
        vector<bool> vis(n, false);
        q.push(start); vis[start] = true;
        while(!q.empty())
        {
            long long int curri = q.front();
            q.pop();
            if(arr[curri] == 0) return true;
            if(curri+arr[curri] < n && !vis[curri+arr[curri]]) {q.push(curri+arr[curri]); vis[curri+arr[curri]] = true;}
            if(curri-arr[curri] >= 0 && !vis[curri-arr[curri]]) {q.push(curri-arr[curri]); vis[curri-arr[curri]] = true;}
        }
        return false;
    }
};