#include <bits/stdc++.h>
#define oo 1001007000
#define ooo 5223372036854775807
#define endl "\n"
#define r0 return 0

using namespace std;

bool is_pal (string str)
{
    string tmp = str;
    reverse(tmp.begin(), tmp.end());
    if(tmp == str)
        return 1;
    else
        return 0;
}

signed main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    string a, b, c;
    cin >> a;

    if(is_pal(a))
    {
        cout << a << endl;
        return 0;
    }

    b = a;
    c = a;
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());

    string res_str_1, res_str_2;

    while((a+b).size() != a.size())
    {
        if(is_pal(a+b))
        {
            res_str_1 = a + b;
        }
        b.erase(0,1);
    }

    while((c+a).size() != a.size())
    {
        if(is_pal(c+a))
        {
            res_str_2 = c + a;
        }
        c.erase(c.size() - 1, 1);
    }

    cout << ((res_str_1.size() <= res_str_2.size()) ? res_str_1 : res_str_2) << endl;

    return 0;
}
