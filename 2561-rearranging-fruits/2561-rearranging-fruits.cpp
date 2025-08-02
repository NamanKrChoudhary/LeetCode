class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<long long int, long long int> bs1, bs2, in1, in2;
        for(auto i: basket1) bs1[i]++;
        for(auto i: basket2) bs2[i]++;
        set<long long int> sorted;
        for(auto i: bs1)
        {
            if(bs2.find(i.first) == bs2.end()) in1[i.first] = i.second;
            else if(bs2[i.first] < i.second) in1[i.first] = i.second-bs2[i.first];
        }
        for(auto i: bs2)
        {
            if(bs1.find(i.first) == bs1.end()) in2[i.first] = i.second;
            else if(bs1[i.first] < i.second) in2[i.first] = i.second-bs1[i.first];
        }
        for(auto i: bs1) 
        {
            if(in1.find(i.first) == in1.end()) sorted.insert(i.first);
            else if(in1[i.first] < bs1[i.first]) sorted.insert(i.first);
        }
        bool check = true;
        for(auto i: in1) if(i.second%2 == 1) {check = false; break;}
        for(auto i: in2) if(i.second%2 == 1) {check = false; break;}
        //if(in1.size() != in2.size() || check == false) return -1;
        if(check == false) return -1;
        for(auto i: in1) in1[i.first] = i.second/2;
        for(auto i: in2) in2[i.first] = i.second/2;
        vector<long long int> curr1, curr2, curr;
        for(auto i: in1) for(int j=0; j<i.second; j++) {curr1.push_back(i.first); curr.push_back(i.first);}
        for(auto i: in2) for(int j=0; j<i.second; j++) {curr2.push_back(i.first); curr.push_back(i.first);}
        if(curr1.size() != curr2.size()) return -1;
        sort(curr.begin(), curr.end());
        long long int mincost = 0;
        for(int i=0; i<curr.size()/2; i++) 
        {
            if(!sorted.empty())
            {
                long long int cc = *sorted.begin();
                if(cc*2 <= curr[i]) mincost = mincost + (cc*2); 
                else mincost = mincost + curr[i];
            }
            else mincost = mincost + curr[i];  
            sorted.insert(curr[i]);
        }
        return mincost;
    }
};