#include <bits/stdc++.h>
#include <cctype>

using namespace std;

struct Token {
    int type;
    union{
        long long num; //type 1
        char op; // type 2
    } val;
};

bool Is_op (char &c)
{
    for (char op : "+-*/%")
        if (c == op)
            return true;
    return false;
}

int priority (char smb)
{
    if(smb == '+' or smb == '-') return 1;
    if(smb == '*' or smb == '/' or smb == '%') return 2;
    if(smb == 'p' or smb == 'm') return 3;
    if(smb == 's' or smb == 'c') return 4;
    if(smb == '(' or smb == ')') return 0;
    return 999;
}

bool Bracket_correctness (string &Str, int &i_size)
{
    int bracket = 0;

    for(int i = 0; i < i_size; i++)
    {
        if(Str[i] == '(') bracket++;
        if(i != i_size - 1 and Str[i] == '(')
            if(Str[i+1] == ')') return 0;
        if(Str[i] == ')')
            if(bracket <= 0) return 0;
            else bracket--;
    }

    if(bracket) return 0;

    return 1;
}

bool sin_cos_correctness (string &Input, vector<int> &v)
{

    string cur_str = Input;

    int cur_str_size = Input.size();

    if(v.empty())
    {
        for(int i = 0; i < cur_str_size; i++)
        {
            if(cur_str[i] >= 'a' and cur_str[i] <= 'z') return 0;
        }

        return 1;
    }

    for(int i = 1; i < cur_str_size - 1; i++)
    {
        if(cur_str[i] == 's' and cur_str[i-1] == 'o' and cur_str[i+1] == 'i') return 0;
    }

    if(cur_str[cur_str_size - 1] == 'n') return 0;
    if(cur_str[cur_str_size - 2] == 'o') return 0;

    for(int i = v.size() - 1; i>=0; i--)
    {
        cur_str.erase(v[i], 3);
        cur_str_size-=3;
    }

    cur_str_size = cur_str.size();

    for(int i = 0; i < cur_str_size; i++)
    {
        if(cur_str[i] >= 'a' and cur_str[i] <= 'z') return 0;
    }

    return 1;
}

bool Input_correctness (string &Input)
{
    while(*Input.begin() == ' '  and Input.begin() != Input.end()) Input.erase(Input.begin());
    reverse(Input.begin(), Input.end());

    while(*Input.begin() == ' '  and Input.begin() != Input.end()) Input.erase(Input.begin());
    reverse(Input.begin(), Input.end());

    if(!Input.size()) return 0;

    if(Input == "0") exit(0);

    int i_size = Input.size();

    if(Is_op(Input[i_size - 1])) return 0;

    if(Input[0] == '*'
       or Input[0] == '/'
       or Input[0] == '%') return 0;

    if(!Bracket_correctness(Input, i_size)) return 0;

    i_size = Input.size();

    for(int i = i_size - 2; i >= 0 ; i--)
    {
        if(Input[i] == ' ' and Input[i + 1] == ' ')
        {
            Input.erase(Input.begin() + i + 1);
            i_size--;
        }
    }

    i_size = Input.size();

    for(int i = 0; i < i_size; i++)
    {
        if(Is_op(Input[i]))
        {
            if(i >= 1)
                if(Is_op(Input[i - 1])) return 0;
            if(i < i_size - 1)
                if(Is_op(Input[i + 1])) return 0;

            if(i >= 2)
                if(Input[i - 1] == ' ' and Is_op(Input[i - 2])) return 0;
            if(i < i_size - 2)
                if(Input[i + 1] == ' ' and Is_op(Input[i + 2])) return 0;
        }
        if(Input[i] == '(')
        {
            if(i < i_size - 1)
                if(Is_op(Input[i + 1]) and Input[i + 1] != '+' and Input[i + 1] != '-') return 0;
            if(i < i_size - 2)
                if(Input[i + 1] == ' ' and Is_op(Input[i + 2]) and Input[i + 2] != '+' and Input[i + 2] != '-') return 0;
        }
        if(Input[i] == ')')
        {
            if(i >= 1)
            {
                if(Is_op(Input[i - 1]) and Input[i - 1] != '+' and Input[i - 1] != '-') return 0;
            }
            if(i >= 2)
            {
                if(Input[i - 1] == ' ' and Is_op(Input[i - 2])) return 0;
            }
        }
    }

    for(int i = 0; i < i_size; i++)
    {
        if(Input[i] >= 'A' and Input[i] <= 'Z')
            Input[i] = tolower(Input[i]);
    }

    for(int i = 0; i < i_size; i++)
    {
        if( Input[i] != '+'
            and Input[i] != '-'
            and Input[i] != '*'
            and Input[i] != '/'
            and Input[i] != '%'
            and Input[i] != '('
            and Input[i] != ')'
            and Input[i] != ' ')
            if(Input[i] - '0' < 0 or Input[i] - '0' > 9)
                if( Input[i]!= 's'
                    and Input[i]!= 'i'
                    and Input[i]!= 'n'
                    and Input[i]!= 'c'
                    and Input[i]!= 'o') return 0;
    }

    vector <int> sin_cos_beg;

    for(int i = 0; i < i_size - 2; i++)
    {
        if(Input[i] == 's' and Input[i+1] == 'i' and Input[i+2] == 'n') sin_cos_beg.push_back(i);
        if(Input[i] == 'c' and Input[i+1] == 'o' and Input[i+2] == 's') sin_cos_beg.push_back(i);
    }

    if(!sin_cos_correctness(Input, sin_cos_beg)) return 0;

    return 1;
}

void Normalize_Input (string &Input)
{
    int i_size = Input.size();

    for(int i = i_size - 2; i >= 1; i--)
    {
        if( Input[i] == ' '
            and Input[i + 1] >= '0' and Input[i + 1] <= '9'
            and Input[i - 1] >= '0' and Input[i - 1] <= '9')
        {
            Input.insert(i + 1, "* ");
            continue;
        }
    }

    i_size = Input.size();

    for(int i = i_size - 1; i >=0; i--)
    {
        if(Is_op(Input[i])
           or Input[i] == '('
           or Input[i] == ')')
        {
            if(i < i_size - 1) if(Input[i+1]!=' ')
                    Input.insert(Input.begin() + i + 1, ' ');
            if(i > 0) if(Input[i-1]!=' ')
                    Input.insert(Input.begin() + i, ' ');
        }
    }

    i_size = Input.size();

    for(int i = i_size - 1; i >=0; i--)
    {
        if(i < i_size - 1)
            if(Input[i] == 'n' and Input[i+1] != ' ') Input.insert(Input.begin() + i + 1, ' ');
        if(i < i_size - 2)
            if(Input[i] == 'o' and Input[i+2] != ' ') Input.insert(Input.begin() + i + 2, ' ');
        if(i > 0)
            if(Input[i] == 'c' and Input[i-1] != ' ') Input.insert(Input.begin() + i, ' ');
        if(i > 1)
            if(Input[i] == 'i' and Input[i-2] != ' ') Input.insert(Input.begin() + i - 1, ' ');
    }

    i_size = Input.size();

    for(int i = i_size - 1; i >= 0; i--)
    {
        if(Input[i] == 'c' and i>=2)
            if(Input[i - 2] >= '0' and Input[i - 2] <= '9')
                Input.insert(i, "* ");
        if(Input[i] == 'i' and i >= 3)
            if(Input[i - 3] >= '0' and Input[i - 3] <= '9')
                Input.insert(i - 1, "* ");
        if(Input[i] == ')' and i < i_size - 2)
            if(Input[i + 2] >= '0' and Input[i + 2] <= '9')
                Input.insert(i + 1, " *");
        if(Input[i] == '(' and i>=2)
            if(Input[i - 2] >= '0' and Input[i - 2] <= '9')
                Input.insert(i, "* ");
    }

}

vector <Token> Input_to_tokens (string &Input)
{
    Input+=' ';

    vector <Token> tokens;

    int l = 0;
    int i_size = Input.size();

    string tmp = "";

    while(l < i_size)
    {
        if(Input[l] != ' ')
        {
            tmp+=Input[l];
        }
        else
        {
            Token cur_token;

            if(tmp.size() == 1 and (Is_op(tmp[0]) or tmp[0] == '(' or tmp[0] == ')'))
            {
                    cur_token.type = 2;
                    cur_token.val.op = tmp[0];

                    if(tmp[0] == '+' or tmp[0] == '-')
                    {
                        if (!tokens.size())
                        {
                            cur_token.val.op = ((tmp[0] == '+') ? ('p') : ('m'));
                        }
                        else if (tokens[tokens.size() - 1].type == 2)
                        {
                            cur_token.val.op = ((tmp[0] == '+') ? ('p') : ('m'));
                        }
                    }
            }
            else if(tmp[0] == 's' or tmp[0] == 'c')
            {
                cur_token.type = 2;
                cur_token.val.op = tmp[0];
            }
            else
            {
                cur_token.type = 1;

                if(!tokens.empty() and tokens[tokens.size() - 1].type == 2 and tokens[tokens.size() - 1].val.op == 'm')
                {
                    cur_token.val.num = - stoi(tmp);
                    tokens.pop_back();
                }
                else
                    cur_token.val.num = stoi(tmp);
            }
            tmp="";
            if(!(cur_token.type == 2 and cur_token.val.op == 'p'))
                tokens.push_back(cur_token);
        }
        l++;
    }

    return tokens;
}

vector <Token> Input_to_RPN (string &Input)
{
    vector <Token> tokens_from_input = (Input_to_tokens(Input));

    vector <Token> tokens_in_rpn;

    stack <Token> operations;

    for (Token token : tokens_from_input)
    {
        if (token.type == 1)
            tokens_in_rpn.push_back(token);
        else
        {
            if (token.val.op == 's' or token.val.op == 'c' or token.val.op == '(')
            {
                operations.push(token);
            }
            else if (token.val.op == ')')
            {
                while (operations.top().val.op != '(')
                {
                    tokens_in_rpn.push_back(operations.top());
                    operations.pop();
                }
                operations.pop();

                if (!operations.empty() and (operations.top().val.op == 's' or operations.top().val.op == 'c'))
                {
                    tokens_in_rpn.push_back(operations.top());
                    operations.pop();
                }
            }
            else
            {
                while (!operations.empty() and priority(token.val.op) <= priority(operations.top().val.op))
                {
                    tokens_in_rpn.push_back(operations.top());
                    operations.pop();
                }
                operations.push(token);
            }
        }
    }
    while (!operations.empty())
    {
        tokens_in_rpn.push_back(operations.top());
        operations.pop();
    }

    return tokens_in_rpn;
}

pair <bool, double> Calculate (vector <Token> tokens_in_rpn)
{
    stack <double> values;

    for(Token token : tokens_in_rpn)
    {
        if(token.type == 1)
            values.push((double)token.val.num);
        else
        {
            switch (token.val.op)
            {
                case '+' :
                {
                    double y = values.top();
                    values.pop();
                    double x = values.top();
                    values.pop();
                    values.push(x + y);
                    break;
                }
                case '-' :
                {
                    double y = values.top();
                    values.pop();
                    double x = values.top();
                    values.pop();
                    values.push(x - y);
                    break;
                }
                case '*' :
                {
                    double y = values.top();
                    values.pop();
                    double x = values.top();
                    values.pop();
                    values.push(x * y);
                    break;
                }
                case '/' :
                {
                    double y = values.top();
                    if(y == 0.0)
                    {
                        cout << "Error. Division by zero" << endl;
                        return {false, 0.0};
                    }
                    values.pop();
                    double x = values.top();
                    values.pop();
                    values.push(x / y);
                    break;
                }
                case '%' :
                {
                    double y = values.top();
                    if(y == 0.0)
                    {
                        cout << "Error. Division by zero" << endl;
                        return pair <bool, double> (false, 0.0);
                    }
                    values.pop();
                    double x = values.top();
                    values.pop();
                    values.push((int)x % (int)y);
                    break;
                }
                case 's' :
                {
                    double x = values.top();
                    values.pop();
                    values.push(sin(x));
                    break;
                }
                case 'c' :
                {
                    double x = values.top();
                    values.pop();
                    values.push(cos(x));
                    break;
                }
                case 'p' :
                {
                    break;
                }
                case 'm' :
                {
                    double x = values.top();
                    values.pop();
                    values.push(-x);
                    break;
                }
            }
        }
    }

    return pair <bool, double> (true, values.top());
}

signed main()
{
    string Input;

    while(true)
    {
        cout << "Enter the expression or type 0 to exit : " << endl;

        getline(cin, Input);

        if(!Input_correctness(Input)) {cout << "Incorrect input. Try again." << endl << endl; continue;}

        Normalize_Input(Input);

        cout << Input << endl;

        /*
        vector <Token> v = Input_to_RPN(Input);
        for(Token token : v)
        {
            if(token.type == 1)
            cout << token.val.num << ' ';
            else
                cout << token.val.op << ' ';
        }
        cout << endl;
        */

        pair <bool, double> calculation_result = Calculate(Input_to_RPN(Input));

        if(calculation_result.first)
        {
            if(calculation_result.second - (int) calculation_result.second)
                cout << fixed << setprecision(3) << calculation_result.second << endl;
            else
                cout << (int) calculation_result.second << endl;

        }

        cout << endl;

    }

    return 0;
}
