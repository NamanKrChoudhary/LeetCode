class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        set<pair<long long int, long long int>> intervals;
        multiset<long long int> spanlen;
        char prev = s[0];
        long long int cnt = 0;
        long long int n = s.size();
        pair<long long int, long long int> span = {0, -1};
        
        for(int i=0; i<n; i++)
        {
            if(prev == s[i]) cnt = cnt + 1;
            else
            {
                span.second = i-1;
                intervals.insert(span);
                spanlen.insert(cnt);
                cnt = 1;
                prev = s[i];
                span = {i, -1};
            }
        }
        span.second = n-1;
        intervals.insert(span);
        spanlen.insert(cnt);
        
        long long int len = queryCharacters.size();
        vector<int> req;
        
        for(int i=0; i<len; i++)
        {
            long long int curri = queryIndices[i];
            auto it = intervals.lower_bound({curri, 0});
            if(it == intervals.end() || it->first > curri) it--;
            pair<long long int, long long int> currspan = *it;
            char currchar = s[curri], nextchar = queryCharacters[i];
            
            if(currchar == nextchar) {
                req.push_back(*spanlen.rbegin()); 
                continue;
            }
            
            if(currspan.first < curri && currspan.second > curri)
            {
                intervals.erase(it);
                intervals.insert({currspan.first, curri-1});
                intervals.insert({curri, curri});
                intervals.insert({curri+1, currspan.second});
                
                auto it1 = spanlen.find(currspan.second-currspan.first+1);
                spanlen.erase(it1);
                spanlen.insert(1); 
                spanlen.insert(curri-1-currspan.first+1); 
                spanlen.insert(currspan.second-(curri+1)+1);
            }
            else
            {
                bool checker = false;
                if(currspan.first == curri && currspan.first > 0)
                {
                    auto previt = it;
                    previt--;
                    pair<long long int, long long int> prevspan = *previt;
                    if(s[prevspan.first] == nextchar)
                    {
                        pair<long long int, long long int> newspan1 = {prevspan.first, currspan.first}, newspan2 = {-1, -1};
                        if(currspan.second > currspan.first) {newspan2.first = currspan.first + 1; newspan2.second = currspan.second;}
                        
                        intervals.erase(it);
                        intervals.erase(previt);
                        intervals.insert(newspan1);
                        if(newspan2.first != -1) intervals.insert(newspan2);
                        
                        auto it1 = spanlen.find(currspan.second-currspan.first+1);
                        spanlen.erase(it1);
                        auto it2 = spanlen.find(prevspan.second-prevspan.first + 1);
                        spanlen.erase(it2);
                        
                        spanlen.insert(currspan.first-prevspan.first+1);
                        if(newspan2.first != -1) spanlen.insert(currspan.second - currspan.first);
                        
                        it = intervals.lower_bound({curri,0});
                        if(it == intervals.end() || it->first > curri) it--;
                        currspan = *it;
                        checker = true;
                    }
                }
                
                if(currspan.second == curri && currspan.second < n-1)
                {
                    auto nextit = it;
                    nextit++;
                    if(nextit != intervals.end()) {
                        pair<long long int, long long int> nextspan = *nextit;
                        if(s[nextspan.first] == nextchar)
                        {
                            if(checker) 
                            {
                                pair<long long int, long long int> combined = {currspan.first, nextspan.second};
                                intervals.erase(it);
                                intervals.erase(nextit);
                                intervals.insert(combined);
                                
                                auto it1 = spanlen.find(currspan.second - currspan.first + 1);
                                spanlen.erase(it1);
                                auto it2 = spanlen.find(nextspan.second - nextspan.first + 1);
                                spanlen.erase(it2);
                                
                                spanlen.insert(combined.second - combined.first + 1);
                            } 
                            else 
                            {
                                pair<long long int, long long int> newspan1 = {-1, -1}, newspan2 = {curri, nextspan.second};
                                if(currspan.second > currspan.first) {newspan1.first = currspan.first; newspan1.second = currspan.second - 1;}
                                
                                intervals.erase(it);
                                intervals.erase(nextit);
                                if(newspan1.first != -1) intervals.insert(newspan1);
                                intervals.insert(newspan2);
                                
                                auto it1 = spanlen.find(currspan.second-currspan.first+1);
                                spanlen.erase(it1);
                                auto it2 = spanlen.find(nextspan.second-nextspan.first + 1);
                                spanlen.erase(it2);
                                
                                if(newspan1.first != -1) spanlen.insert(currspan.second - currspan.first);
                                spanlen.insert(nextspan.second - curri + 1);
                                
                                checker = true;
                            }
                        }
                    }
                }
                
                if(!checker)
                {
                    intervals.erase(it);
                    auto it1 = spanlen.find(currspan.second - currspan.first + 1);
                    spanlen.erase(it1);
                    
                    intervals.insert({curri, curri});
                    spanlen.insert(1);
                    
                    if(currspan.first < curri)
                    {
                        intervals.insert({currspan.first, curri - 1});
                        spanlen.insert(curri - 1 - currspan.first + 1);
                    }
                    if(currspan.second > curri)
                    {
                        intervals.insert({curri + 1, currspan.second});
                        spanlen.insert(currspan.second - (curri + 1) + 1);
                    }
                }
            }
            
            s[curri] = nextchar;
            req.push_back(*spanlen.rbegin());
        }
        return req;
    }
};