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

map <int,int> m;

vector <int> prime_div;

bool is_prime (ll a)
{
    if(a == 2) return 1;

    if(a%2 == 0) return 0;

    for(ll i = 2;  i*i <= a; i++)
    {
        if(a % i == 0) return 0;
    }

    return 1;
}

void get_div (ll n)
{
    for(ll i = n; i > 1; i--)
    {
        if(is_prime(i))
        {
            prime_div.push_back(i);
        }
    }
}

signed main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    ll n;

    cin >> n;

    get_div(n);

    for(ll j = 2; j <= n; j++)
    {
        ll num = j;

        for(int i = 0; i < prime_div.size(); i++)
        {
            while(num%prime_div[i] == 0)
            {
                num/=prime_div[i];
                m[prime_div[i]]++;
            }
        }
    }

//    for(int x : prime_div)
//        cout << x << endl;

    for(auto &x : m)
    {
        cout << "{" << x.first << " ," << x.second << "}" << endl;
    }

    return 0;
}
