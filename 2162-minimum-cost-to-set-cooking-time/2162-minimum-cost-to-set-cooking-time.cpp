class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int mins1 = targetSeconds/60;
        int secs1 = targetSeconds%60;
        int mins2 = mins1-1;
        int secs2 = secs1 + 60;
        int curr = startAt;
        int reqcost1 = 1e9;
        //cout << mins1 << " " << secs1 << endl;
        // cout << mins2 << " " << secs2 << endl;
        if(mins1 >= 0 && mins1 < 100 && secs1 >= 0 && secs1 < 100)
        {
            reqcost1 = 0;
            vector<int> temp;
            int tempmin = mins1, tempsecs = secs1;
            while(tempsecs > 0)
            {
                temp.push_back(tempsecs%10);
                tempsecs = tempsecs/10;
            }
            if(tempmin != 0) 
            {
                while(temp.size() < 2) temp.push_back(0);
            }
            while(tempmin > 0) 
            {
                temp.push_back(tempmin%10);
                tempmin = tempmin/10;
            }
            reverse(temp.begin(), temp.end());
            //for(auto i: temp) cout << i << " "; cout << endl;
            for(int i=0; i<temp.size(); i++)
            {
                if(curr != temp[i]) reqcost1 = reqcost1 + moveCost;
                curr = temp[i];
                reqcost1 = reqcost1 + pushCost;
                //cout << temp[i] << " " << reqcost1 << endl;
            }
        }
        //cout << reqcost1 
        int reqcost2 = 1e9;
        curr = startAt;
        //cout << mins2 << " " << secs2 << endl;
        if(mins2 >= 0 && mins2 < 100 && secs2 >= 0 && secs2 < 100)
        {
            reqcost2 = 0;
            vector<int> temp;
            int tempmin = mins2, tempsecs = secs2;
            while(tempsecs > 0)
            {
                temp.push_back(tempsecs%10);
                tempsecs = tempsecs/10;
            }
            if(tempmin > 0) 
            {
                while(temp.size() < 2) temp.push_back(0);
            }
            while(tempmin > 0) 
            {
                temp.push_back(tempmin%10);
                tempmin = tempmin/10;
            }
            reverse(temp.begin(), temp.end());
            for(int i=0; i<temp.size(); i++)
            {
                if(curr != temp[i]) reqcost2 = reqcost2 + moveCost;
                curr = temp[i];
                reqcost2 = reqcost2 + pushCost;
            }
        }
        //cout << reqcost1 << " " << reqcost2 << endl;
        return min(reqcost1, reqcost2);
    }
};