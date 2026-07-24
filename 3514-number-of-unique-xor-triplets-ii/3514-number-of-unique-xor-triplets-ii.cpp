class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> first(4e3, false);
        vector<bool> second(4e3, false);
        vector<bool> third(4e3, false);
        for(int i=0; i<nums.size(); i++) first[nums[i]] = true;
        for(int i=0; i<first.size(); i++)
        {
            if(first[i])
            {
                for(int j=0; j<first.size(); j++)
                {
                    if(first[j])
                    {
                        int curr = i^j;
                        second[curr] = true;
                    }
                }
                third[i] = true;
            }
        }
        for(int i=0; i<second.size(); i++)
        {
            if(second[i])
            {
                for(int j=0; j<first.size(); j++)
                {
                    if(first[j])
                    {
                        int curr = i^j;
                        third[curr] = true;
                        //cout << curr << endl;
                    }
                }
            }
        }
        int req = 0;
        for(int i=0; i<third.size(); i++) if(third[i]) req = req + 1;
        return req;
    }
};