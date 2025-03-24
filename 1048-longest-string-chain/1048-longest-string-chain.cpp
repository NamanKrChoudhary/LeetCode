class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<string> arr = words;
        sort(arr.begin(), arr.end(), [](string a, string b)
        {
            return a.size() < b.size();
        });
        vector<int> brr(arr.size());
        long long int n = arr.size();
        for(int i=0; i<arr.size(); i++)
        {
            int temp = 1;
            for(int j=0; j<i; j++)
            {
                if(arr[i].size()-1 == arr[j].size())
                {
                    bool check = false;
                    bool checker = false;
                    for(int k=0,l=0; k<arr[i].size() && l<arr[j].size(); k++, l++)
                    {
                        if(arr[i][k] != arr[j][l] && check){checker = true; break;}
                        else if(arr[i][k] != arr[j][l]){check = true; l--; continue;} 
                    }
                    if(checker) continue;
                    else temp = max(temp, 1+brr[j]);
                }
            }
            brr[i] = temp;
        }
        int ans = 1;
        for(int i=0; i<arr.size(); i++) ans = max(ans,brr[i]);
        return ans;
    }
};