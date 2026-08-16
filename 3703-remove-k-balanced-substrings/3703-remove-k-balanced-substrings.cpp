class Solution {
public:
    string removeSubstring(string s, int k) {
        long long int n = s.size();
        vector<vector<long long int>> p;
        long long int tempcurr = 0;
        bool check = true;
        if(s[0] == ')') check = false;
        for(int i=0; i<n; i++)
        {
            if(check == true && s[i] == '(') tempcurr = tempcurr + 1;
            else if(check == false && s[i] == ')') tempcurr = tempcurr + 1;
            else if(check == true && s[i] == ')')
            {
                p.push_back({tempcurr, check});
                tempcurr = 1;
                check = false;
            }
            else if(check == false && s[i] == '(') 
            {
                p.push_back({tempcurr, check});
                tempcurr = 1;
                check = true;
            }
        }
        p.push_back({tempcurr, check});
        //for(int i=0; i<p.size(); i++) cout << p[i][0] << " " << p[i][1] << endl;
        vector<vector<long long int>> st;
        for(int i=0; i<p.size(); i++)
        {
            //cout << i << endl;
            st.push_back(p[i]);
            // for(int j=0; j<st.size(); j++) cout << st[j][0] << " " << st[j][1] << endl;
            // cout << endl;
            if(st.size() > 1)
            {
                //long long int st.size() = st.size();
                if(st[st.size()-1][1] == st[st.size()-2][1])
                {
                    st[st.size()-2][0] = st[st.size()-2][0]+st[st.size()-1][0]; 
                    st.pop_back();
                    continue;
                }
                while(st.size() > 1 && st[st.size()-1][1] == 0 && st[st.size()-1][0] >= k && st[st.size()-2][0] >= k)
                {
                    long long int left = st[st.size()-2][0], right = st[st.size()-1][0];
                    st.pop_back(); st.pop_back();
                    //if(i == 5) cout << left << " " << right << endl;
                    if(left < right)
                    {
                        if(left%k == 0)
                        {
                            st.push_back({right-(k*(left/k)), 0});
                        }
                        else
                        {
                            st.push_back({left%k, 1});
                            st.push_back({right-(k*(left/k)), 0});
                        }
                    }
                    else if(right < left)
                    {
                        if(right%k == 0)
                        {
                            st.push_back({left-(k*(right/k)), 1});
                        }
                        else 
                        {
                            st.push_back({left-(k*(right/k)), 1});
                            st.push_back({right%k, 0});
                        }
                    }
                    else 
                    {
                        if(right%k != 0) 
                        {
                            st.push_back({left%k, 1});
                            st.push_back({right%k, 0});
                        }
                    }
                    //st.size() = st.size();
                    if(st.size() > 1)
                    {
                        //long long int st.size() = st.size();
                        if(st[st.size()-1][1] == st[st.size()-2][1])
                        {
                            st[st.size()-2][0] = st[st.size()-2][0]+st[st.size()-1][0]; 
                            st.pop_back();
                        }
                    }
                }
                // for(int j=0; j<st.size(); j++) cout << st[j][0] << " " << st[j][1] << endl;
                // cout << endl;
                // else
                // {
                //     continue;
                // }
            }
        }
        string req = "";
        //for(int i=0; i<st.size(); i++) cout << st[i][0] << " " << st[i][1] << endl;
        for(int i=0; i<st.size(); i++)
        {
            for(int j=0; j<st[i][0]; j++)
            {
                if(st[i][1] == 1) req.push_back('(');
                else req.push_back(')');
            }
        }
        return req;
    }
};