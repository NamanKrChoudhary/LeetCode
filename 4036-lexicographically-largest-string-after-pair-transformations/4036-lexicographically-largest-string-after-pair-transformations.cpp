class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        long long int n = nums.size();
        vector<string> req(n);
        for(int i=0; i<n; i++)
        {
            vector<int> bits;
            long long int temp = nums[i];
            while(temp)
            {
                bits.push_back(temp%2);
                temp = temp/2;
            }
            //reverse(bits.begin(), bits.end());
            string curr = "";
            for(int j=0; j<bits.size(); j++)
            {
                if(bits[j] == 1)
                {
                    if(j < 26) {curr.push_back('a'+j); continue;}
                    else
                    {
                        long long int noz = pow(2, (j-25));
                        for(int k=0; k<noz; k++) curr.push_back('z');
                    }
                }
            }
            reverse(curr.begin(), curr.end());
            req[i] = curr;
        }
        return req;
    }
};