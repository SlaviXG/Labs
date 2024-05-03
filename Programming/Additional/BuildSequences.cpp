#include <bits/stdc++.h>
#define endl "\n"
#define r0 return 0

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

void sequence(int nend, int k, std::string str, int beg = 1)
{

    if (str.size() == k) std::cout << str << "\n";

    else
    {
        for (int i = beg; i <= nend; i++)
        {
            sequence(nend, k, str + std::to_string(i), i);
        }
    }
}

signed main()
{

    sequence(2, 3, "");

    return 0;
}
