//Bucket sort & Brian Kerninghan's Algorithm
class Solution {
public:
    int HammingWeight(int x){//Brian Kerninghan's Algorithm
        int wt=0;
        while(x>0)
            x&=(x-1), wt++;
        return wt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> B(32);
        for(int x :arr)
            B[HammingWeight(x)].push_back(x);

        for (auto& b: B)
            sort(b.begin(), b.end());
        int count=0;
        for(int i=0; i<32; i++)
            for(int x: B[i])
                arr[count++]=x;
        return arr;
    }
};