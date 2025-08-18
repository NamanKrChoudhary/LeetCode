class Solution {
public:
    map<char, long double> signpr;
    map<char, long double> nums;
    // infix to postfix then evaluation of postfix
    long double evaluate(string& expression)
    {
        queue<char> out;
        stack<char> ops;
        for(int i=0; i<expression.size(); i++)
        {
            if(nums.find(expression[i]) != nums.end()) out.push(expression[i]);
            else if(expression[i] == '(') ops.push('(');
            else if(expression[i] == ')')
            {
                while(ops.top() != '(')
                {
                    char curr = ops.top();
                    ops.pop();
                    out.push(curr);
                }
                ops.pop();
            }
            else
            {
                while(!ops.empty())
                {
                    char curr = ops.top();
                    if(signpr[expression[i]] > signpr[curr]) break;
                    out.push(curr);
                    ops.pop();
                }
                ops.push(expression[i]);
            }
        }
        while(!ops.empty()) {out.push(ops.top()); ops.pop();}

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
        return eval.top();
    }
    // infix convertor for all possible arrangements with brackets.
    bool convert(vector<int>& nos, vector<bool>& vis, vector<char>& operations, bool open, bool num, bool ops, bool close, string& expression, long long int curropen)
    {
        if(close && vis[0] && vis[1] && vis[2] && vis[3])
        {
            for(int i=0; i<curropen; i++) expression.push_back(')');
            long long int eval = evaluate(expression);
            for(int i=0; i<curropen; i++) expression.pop_back();
            if(abs(24-eval) < 1e-9) return true;
            else return false;
        }

        else if(open)
        {
            bool check1 = convert(nos, vis, operations, false, true, false, false, expression, curropen);
            expression.push_back('(');
            bool check2 = convert(nos, vis, operations, false, true, false, false, expression, curropen+1);
            expression.pop_back();
            if(check1 || check2) return true;
            else return false;
        }

        else if(num)
        {
            for(int i=0; i<4; i++)
            {
                if(!vis[i])
                {
                    expression.push_back('0'+nos[i]);
                    vis[i] = true;
                    bool check1 = convert(nos, vis, operations, false, false, false, true, expression, curropen);
                    expression.pop_back();
                    vis[i] = false;
                    if(check1) return true;
                }
            }
            return false;
        }

        else if(close)
        {
            for(int i=0; i<=curropen; i++)
            {
                for(int j=1; j<=i; j++) expression.push_back(')');
                bool check1 = convert(nos, vis, operations, false, false, true, false, expression, curropen-i);
                for(int j=1; j<=i; j++) expression.pop_back();
                if(check1) return true;
            }
            return false;
        }

        else
        {
            for(int i=0; i<4; i++)
            {
                expression.push_back(operations[i]);
                bool check1 = convert(nos, vis, operations, true, false, false, false, expression, curropen);
                expression.pop_back();
                if(check1) return true;
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
        return convert(cards, vis, operations, true, false, false, false, expression, 0);
    }
};