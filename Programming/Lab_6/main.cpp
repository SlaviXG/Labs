#include <bits/stdc++.h>
#include <fstream>

void ReadFile(const std::string name, std::string &input);

void ClearInput(std::string &input);

std::vector <std::string> InputToTerms(std::string &input);

void NormalizeTerms (std::vector <std::string> &terms);

std::string Calculate (std::vector <std::string> &terms);

std::string Sum (std::string &x, std::string &y);

std::string Dif (std::string &x, std::string &y, char &sign_x, char &sign_y);

signed main()
{
    std::string input;
    ReadFile("input.txt", input);
    ClearInput(input);
    std :: cout << input << std :: endl;
    std::vector <std::string> terms = InputToTerms(input);
    NormalizeTerms(terms);

    //for(auto term : terms)
        //std :: cout << term << std :: endl;

    std :: string result = Calculate(terms);
    std :: cout << result << std :: endl;
    return 0;
}

void ReadFile(const std::string name, std::string &input)
{
    input = "";
    std::ifstream fin (name);
    if(fin.is_open())
        for(std::string tmp; getline(fin, tmp); input+=tmp);
}

void ClearInput(std::string &input)
{
    std::string temp = "";
    for(char &smb : input)
    {
        if(smb == '+' || smb == '-' || (smb >= '0' && smb <= '9'))
            temp+=smb;
    }
    while(temp.size() && (temp[temp.size() - 1] == '+' || temp[temp.size() - 1] == '-')) temp.erase(prev(temp.end()));

    while(temp.size()> 1 && (*(temp.begin()) == '+' || *(temp.begin()) == '-') && (*(temp.begin() + 1) == '+' || *(temp.begin() + 1) == '-')) temp.erase(temp.begin());

    input = temp;
}

std::vector <std::string> InputToTerms(std::string &input)
{
    std::vector <std::string> Terms;
    input+=" ";
    std :: string tmp = "";
    bool finished = 0;
    for(int i = 0; input[i] != ' '; i++)
    {
        tmp+=input[i];
        if(input[i+1] == '+' || input[i+1] == '-' || input[i+1] == ' ')
            finished = 1;

        if(finished)
        {
            Terms.push_back(tmp);
            tmp = "";
            finished = 0;
        }
    }
    return Terms;
}

void NormalizeTerms (std::vector <std::string> &terms)
{
    if(!terms.empty())
        if(terms[0][0] >= '0' and terms[0][0] <= '9')
            terms[0] = "+" + terms[0];
}

std::string Sum (std::string &x, std::string &y)
{
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    if(x.size() > y.size())
        while(y.size() != x.size())
            y+="0";
    else if(y.size() > x.size())
            while(x.size()!=y.size())
                x+="0";
    x+='0';y+='0';
    //std :: cout << x << ' ' << y << std :: endl;
    int len = x.size();
    std::string res(len, '0');
    int z = 0;
    for(int i = 0; i < len; i++)
    {
        int cur = x[i] + y[i] - '0' - '0' + z;
        res[i] += cur%10;
        z = cur/10;
    }
    reverse(res.begin(), res.end());
    if(*(res.begin()) == '0') res.erase(res.begin());
    //std :: cout << res << std :: endl;
    return res;
}

std::string Dif (std::string &x, std::string &y, char &sign_x, char &sign_y)
{
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    if(x.size() > y.size())
        while(y.size() != x.size())
            y+="0";
    else if(y.size() > x.size())
            while(x.size()!=y.size())
                x+="0";
    int len = x.size();
    std::string res(len, '0');
    if(x == y) return "+0";
    bool x_is_bigger = 1;
    for(int i = len - 1; i >= 0; i++)
    {
        if(y[i] > x[i])
        {
            x_is_bigger = 0;
            break;
        }
        if(x[i] > y[i])
            break;
    }
    if(!x_is_bigger)
    {
        std :: swap(x, y);
        std :: swap(sign_x, sign_y);
    }
    bool minus_r = 0;
    bool fmr = 1;
    for(int i = 0; i < len; i++)
    {
        if(x[i] > y[i])
        {
            if(minus_r == 0)
                res[i] = x[i] - y[i] + '0';
            else
            {
                res[i] = x[i] - y[i] - 1 + '0';
                minus_r = 0;
                fmr = 1;
            }
        }
        else if(x[i] == y[i])
        {
            if(minus_r == 0)
            {
                res[i] = '0';
            }
            else
            {
                int temp_res = x[i] - y[i] - 1;
                if(temp_res >=0)
                {
                    res[i] = temp_res + '0';
                    fmr = 1;
                    minus_r = 0;
                }
                else
                {
                    res[i] = temp_res + 10 + '0';
                    fmr = 0;
                }
            }
        }
        else
        {
            if(fmr)
            {
                res[i] = x[i] + 10 - y[i] + '0';
                fmr = 0;
                minus_r = 1;
            }
            else
            {
                res[i] = x[i] + 9 - y[i] + '0';
            }
        }
    }
    while(res.size() > 1 && *(prev(res.end())) == '0') res.erase(prev(res.end()));
    reverse(res.begin(), res.end());
    res=sign_x+res;
    return res;
}

std::string Calculate (std::vector <std::string> &terms)
{
    std :: string result = "+0";

    while(terms.size())
    {
        std :: string term = terms.back();

        char sign_x = *(result.begin());
        char sign_y = *(term.begin());
        term.erase(term.begin());
        result.erase(result.begin());
        if(sign_x == '+' and sign_y == '+')
            result = "+" + Sum (result, term);
        else if(sign_x == '-' and sign_y == '-')
                result = "-" + Sum (result, term);
        else
        {
            result = Dif(result,term, sign_x, sign_y);
        }
        //std::cout << "!!! " << result << std::endl;
        terms.pop_back();
    }

    return result;
}
