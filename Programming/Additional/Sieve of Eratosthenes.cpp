#include <bits/stdc++.h>
#define oo 1001007000
#define ooo 5223372036854775807
#define endl "\n"
#define r0 return 0
#define time_taken 1.0 * clock() / CLOCKS_PER_SEC

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e7;
int lp [N+1]; /// least_prime

signed main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    vector <int> pr; /// prime

    for(int i = 2; i<=N; i++)
    {
        if(lp[i] == 0)
            lp[i] = i,
            pr.push_back(i);

        for(int p : pr)
        {
            if(p*i > N or lp[i] < p)
                break;
            lp[p*i] = p;
        }
    }


    for(int p : pr)
    {
        cout << p << endl;
    }

    return 0;
}
