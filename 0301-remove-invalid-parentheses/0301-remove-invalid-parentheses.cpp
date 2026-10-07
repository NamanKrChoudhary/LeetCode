class Solution {
public:
    void filler(map<string, long long int>& req, long long int currstate, long long int curri, string& s, long long int remavl, string& fin)
    {
        if(curri == s.size())
        {
            if(currstate == 0)
            {
                // string temp = "";
                // for(int i=0; i<s.size(); i++)
                // {
                //     if(remind.find(i) == remind.end()) temp.push_back(s[i]);
                // }
                // req[temp]++;
                req[fin]++;
            }
            return;
        }
        if(s[curri] != '(' && s[curri] != ')') 
        {
            fin.push_back(s[curri]);
            filler(req, currstate, curri+1, s, remavl, fin);
            fin.pop_back();
        }
        if(s[curri] == '(')
        {
            // currstate = currstate + 1;
            // filler(req, currstate, curri+1, s, remavl, remind);
            // currstate = currstate - 1;
            // if(remavl > 0)
            // {
            //     remavl = remavl-1;
            //     remind.insert(curri);
            //     filler(req, currstate, curri+1, s, remavl, remind);
            //     remavl = remavl+1;
            //     remind.erase(curri);
            // }

            long long int cnt = 0;
            for(int i=curri; i<s.size(); i++)
            {
                if(s[i] == '(') cnt = cnt + 1;
                else break;
            }
            for(int i=0; i<cnt; i++) {fin.push_back('('); currstate = currstate + 1;}
            filler(req, currstate, curri+cnt, s, remavl, fin);
            for(int i=1; i<= min(remavl, cnt); i++)
            {
                currstate = currstate - 1;
                fin.pop_back();
                filler(req, currstate, curri+cnt, s, remavl-i, fin);
            }
            if(remavl < cnt) for(int i=0; i<cnt-remavl; i++) {fin.pop_back(); currstate-1;}

        }
        else if(s[curri] == ')')
        {
            
            // if(remavl > 0)
            // {
            //     remavl = remavl - 1;
            //     remind.insert(curri);
            //     filler(req, currstate, curri+1, s, remavl, remind);
            //     remavl = remavl + 1;
            //     remind.erase(curri);
            // }
            // if(currstate > 0)
            // {
            //     //char currtop = currstate.top();
            //     currstate = currstate - 1;
            //     filler(req, currstate, curri+1, s, remavl, remind);
            //     currstate = currstate + 1;
            // }

            long long int cnt = 0;
            for(int i=curri; i<s.size(); i++)
            {
                if(s[i] == ')') cnt = cnt + 1;
                else break;
            }
            if(cnt - currstate <= remavl)
            {
                if(currstate >= cnt)
                {
                    for(int i=0; i<cnt; i++) {fin.push_back(')'); currstate = currstate-1;}
                    filler(req, currstate, curri+cnt, s, remavl, fin);
                    for(int i=1; i<=min(cnt, remavl); i++)
                    {
                        fin.pop_back();
                        currstate = currstate + 1;
                        filler(req, currstate, curri+cnt, s, remavl-i, fin);
                    }
                    if(remavl < cnt) for(int i=0; i<cnt-remavl; i++) {fin.pop_back(); currstate = currstate + 1;}
                }
                else
                {
                    long long int state = currstate;
                    for(int i=0; i<state; i++) {fin.push_back(')'); currstate = currstate-1;}
                    filler(req, currstate, curri+cnt, s, remavl-(cnt-state), fin);
                    long long int currminus = (cnt-state);
                    for(int i=0; i<state; i++)
                    {
                        fin.pop_back();
                        currstate = currstate + 1;
                        currminus = currminus + 1;
                        if(remavl >= currminus) filler(req, currstate, curri+cnt, s, remavl-currminus, fin);
                    }
                }
            }
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        long long int rem = 0;
        long long int n = s.size();
        long long int curr = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(') curr = curr + 1;
            else if(s[i] == ')') curr = curr-1;
            if(curr < 0) {rem = rem + 1; curr = 0;}
        }
        if(curr > 0) rem = rem + curr;


        // vector<pair<char, long long int>> arr;
        // long long int sti = 0;
        // while(sti < n && s[sti] != ')' && s[sti] != '(') sti++;
        // if(sti == n)return {s};
        // char prev = s[sti];
        // curr = 0;
        // for(int i=sti; i<n; i++)
        // {
        //     if(s[i] != ')' && s[i] != '(') continue;
        //     if(s[i] != prev) {arr.push_back({prev, curr}); curr = 1; prev = s[i];}
        //     else if(s[i] == prev) curr = curr + 1;
        // }
        // arr.push_back({prev, curr});


        map<string, long long int> req;
        stack<char> state;
        set<long long int> remind;
        string fin = "";
        filler(req, 0, 0, s, rem, fin);
        vector<string> reqfin;
        for(auto i: req) reqfin.push_back(i.first);
        return reqfin;
    }
};