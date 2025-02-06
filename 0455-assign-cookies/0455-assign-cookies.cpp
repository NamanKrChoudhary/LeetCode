class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        vector<int> arr1 = g, arr2 = s;
        sort(arr1.begin(), arr1.end()); sort(arr2.begin(), arr2.end());
        int i=g.size()-1, j=s.size()-1;
        int ans = 0;
        while(i>=0 && j>=0)
        {
            if(arr1[i] <= arr2[j]){ans = ans+1; i=i-1; j=j-1;}
            else i = i-1;
        }
        return ans;
    }
};