class Solution {
public:
    map<char, long double> signpr;
    map<char, long double> nums;
    // infix to postfix then evaluation of postfix
    long double evaluate(string& expression)
    {
        queue<char> out;
        for(int i=0; i<expression.size(); i++) out.push(expression[i]);

        // evaluation
        stack<long double> eval;
        while(!out.empty())
        {
            char curr = out.front();
            out.pop();
            if(nums.find(curr) != nums.end()) eval.push(nums[curr]);
            else
            {
                long double op1 = eval.top(); eval.pop();
                long double op2 = eval.top(); eval.pop();
                if(curr == '+') eval.push(op2+op1);
                else if(curr == '-') eval.push(op2-op1);
                else if(curr == '*') eval.push(op2*op1);
                else if(curr == '/') 
                {
                    if(op1 == 0) return -1;
                    eval.push(op2/op1);
                }
            }
        }
        //if(expression[0] == '8')cout << expression << " " << eval.top() << endl;
        return eval.top();
        //8 4 - 7 1 - *  
    }
    
    bool convert(string& expression, vector<int>& nos, vector<bool>& vis, vector<char> operations, long long int reqno, long long int reqops)
    {
        if(reqno == 0 && reqops == 0)
        {
            long double check = evaluate(expression);
            if(fabs(check-24) < 1e-9) return true;
            else return false;
        }
        long long int currno = 4-reqno, currops = 3-reqops;
        if(currno == 4) 
        {
            for(int i=0; i<4; i++) 
            {
                expression.push_back(operations[i]);
                bool check = convert(expression, nos, vis, operations, reqno, reqops-1);
                expression.pop_back();
                if(check) return true;
            }
            return false;
        }
        else if(currno-currops > 1)
        {
            for(int i=0; i<4; i++)
            {
                if(!vis[i])
                {
                    expression.push_back('0'+nos[i]);
                    vis[i] = true;
                    bool check = convert(expression, nos, vis, operations, reqno-1, reqops);
                    expression.pop_back();
                    vis[i] = false;
                    if(check) return true;
                }
            }
            for(int i=0; i<4; i++)
            {
                expression.push_back(operations[i]);
                bool check = convert(expression, nos, vis, operations, reqno, reqops-1);
                expression.pop_back();
                if(check) return true;
            }
            return false;
        }
        else
        {
            for(int i=0; i<4; i++)
            {
                if(!vis[i])
                {
                    expression.push_back('0'+nos[i]);
                    vis[i] = true;
                    bool check = convert(expression, nos, vis, operations, reqno-1, reqops);
                    expression.pop_back();
                    vis[i] = false;
                    if(check) return true;
                }
            }
            return false;
        }
    }

    bool judgePoint24(vector<int>& cards) {
        for(int i=0; i<4; i++) nums['0'+cards[i]] = cards[i];
        signpr['-'] = 100; signpr['+'] = 120; signpr['*'] = 130; signpr['/'] = 140; signpr['('] = 50;
        vector<bool> vis(4, false);
        vector<char> operations = {'+', '-', '*', '/'};
        string expression = "";
        for(int i=0; i<4; i++)
        {
            expression.push_back('0'+cards[i]);
            vis[i] = true;
            for(int j=0; j<4; j++)
            {
                if(i == j) continue;
                expression.push_back('0'+cards[j]);
                vis[j] = true;
                bool check = convert(expression, cards, vis, operations, 2, 3);
                vis[j] = false;
                expression.pop_back();
                if(check) return true;
            }
            vis[i] = false;
            expression.pop_back();
        }
        return false;
        // vector<string> pos = {         "a+b+c+d"
        // (a + b) + c + d
        // a + (b + c) + d
        // a + b + (c + d)
        // (a + b) + (c + d)
        // (a + b + c) + d
        // ((a + b) + c) + d
        // (a + (b + c)) + d
        // a + (b + c + d)
        // a + (b + (c + d))
        // a + ((b + c) + d)
        // a + (b + c) + d

    }
};