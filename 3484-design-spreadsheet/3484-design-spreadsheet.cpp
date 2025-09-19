class Spreadsheet {
public:
    vector<vector<long long int>>arr;
    Spreadsheet(int rows) {
        arr.resize(26, vector<long long int>(rows+1));
    }
    
    void setCell(string cell, int value) {
        int i = cell[0]-'A';
        int j = 0;
        for(int k=1; k<cell.size(); k++) {j = j*10 + (cell[k]-'0');}
        arr[i][j] = value;
    }
    
    void resetCell(string cell) {
        int i = cell[0]-'A';
        int j = 0;
        for(int k=1; k<cell.size(); k++) {j = j*10 + (cell[k]-'0');}
        arr[i][j] = 0;
    }
    
    int getValue(string formula) {
        string s1 = "", s2 = "";
        bool check = false;
        for(int i=1; i<formula.size(); i++)
        {
            if(check == false && formula[i] == '+')
            {
                check = true;
                continue;
            }
            else if(check == false)
            {
                s1.push_back(formula[i]);
            }
            else s2.push_back(formula[i]);
        }
        bool check1 = false, check2 = false;
        if(s1[0] >= 'A' && s1[0] <= 'Z') check1 = true;
        if(s2[0] >= 'A' && s2[0] <= 'Z') check2 = true;
        if(check1 && check2)
        {
            int i1 = s1[0]-'A';
            int j1 = 0;
            for(int k=1; k<s1.size(); k++) {j1 = j1*10 + (s1[k]-'0');}
            int i2 = s2[0]-'A';
            int j2 = 0;
            for(int k=1; k<s2.size(); k++) {j2 = j2*10 + (s2[k]-'0');}
            return arr[i1][j1] + arr[i2][j2];
        }
        else if(check1)
        {
            int i1 = s1[0]-'A';
            int j1 = 0;
            for(int k=1; k<s1.size(); k++) {j1 = j1*10 + (s1[k]-'0');}
            int val = 0;
            for(int k=0; k<s2.size(); k++) {val = val*10 + (s2[k]-'0');}
            return arr[i1][j1] + val;
        }
        else if(check2)
        {
            int val = 0;
            for(int k=0; k<s1.size(); k++) {val = val*10 + (s1[k]-'0');}
            int i1 = s2[0]-'A';
            int j1 = 0;
            for(int k=1; k<s2.size(); k++) {j1 = j1*10 + (s2[k]-'0');}
            return arr[i1][j1] + val;
        }
        else
        {
            int val1 = 0;
            for(int k=0; k<s1.size(); k++) {val1 = val1*10 + (s1[k]-'0');}
            int val2 = 0;
            for(int k=0; k<s2.size(); k++) {val2 = val2*10 + (s2[k]-'0');}
            return val1 + val2;
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */