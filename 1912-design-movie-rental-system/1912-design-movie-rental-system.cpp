class MovieRentingSystem {
public:
    map<int, set<pair<int,int>>> moviesavl;
    map<pair<int, int>, int> price;
    set<vector<int>> all;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i=0; i<entries.size(); i++)
        {
            moviesavl[entries[i][1]].insert({entries[i][2], entries[i][0]});
            price[{entries[i][0], entries[i][1]}] = entries[i][2];
            //all.insert({entries[i][2], entries[i][0], entries[i][1]});
            //cout << entries[i][0] << " " << entries[i][1] << " " << entries[i][2] << endl;
        }
        
    }
    
    vector<int> search(int movie) {
        vector<int> temp;
        int j = 1;
        for(auto i: moviesavl[movie])
        {
            temp.push_back(i.second);
            j++;
            if(j > 5) break;
        }
        // cout << movie << endl;
        // for(auto i: moviesavl[movie]) cout << i.second << " "; cout << endl;
        return temp;
    }
    
    void rent(int shop, int movie) {
        moviesavl[movie].erase({price[{shop, movie}], shop});
        all.insert({price[{shop, movie}], shop, movie});
    }
    
    void drop(int shop, int movie) {
        moviesavl[movie].insert({price[{shop, movie}], shop});
        all.erase({price[{shop, movie}], shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> temp;
        int j=1;
        for(auto i: all)
        {
            vector<int> currtemp = {i[1], i[2]};
            temp.push_back(currtemp);
            j++;
            if(j > 5) break;
        }
        return temp;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */