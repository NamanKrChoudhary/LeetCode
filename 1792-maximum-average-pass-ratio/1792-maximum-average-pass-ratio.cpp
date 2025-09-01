class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        vector<vector<int>> curr = classes;
        priority_queue<pair<long double, long long int>> pq;
        for(int i=0; i<curr.size(); i++)
        {
            long double temp1 = curr[i][0]+1;
            temp1 = temp1/(curr[i][1]+1);
            long double temp2 = curr[i][0];
            temp2 = temp2/curr[i][1];
            long double temp3 = temp1-temp2;
            //cout << temp3 << endl;
            pq.push({temp3, i});
        }
        for(int i=0; i<extraStudents; i++)
        {
            pair<long double, long long int> currtemp = pq.top();
            pq.pop();
            long long int currind = currtemp.second;
            //cout << currind << " " << currtemp.first << endl;
            curr[currind][0] = curr[currind][0]+1;
            curr[currind][1] = curr[currind][1]+1;
            long double temp1 = curr[currind][0]+1;
            temp1 = temp1/(curr[currind][1]+1);
            long double temp2 = curr[currind][0];
            temp2 = temp2/curr[currind][1];
            long double temp3 = temp1-temp2;
            //cout << currind << temp3 << endl;
            pq.push({temp3, currind});
        }
        long double curravg = 0;
        //for(int i=0; i<curr.size(); i++) cout << curr[i][0] << " " << curr[i][1] << endl;
        for(int i=0; i<curr.size(); i++)
        {
            long double temp1 = curr[i][0];
            temp1 = temp1/curr[i][1];
            curravg = curravg + temp1;
        }
        curravg = curravg/curr.size();
        return curravg;
    }
};