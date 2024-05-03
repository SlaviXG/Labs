#include <bits/stdc++.h>
#define oo 1001007000
#define ooo 5223372036854775807
#define r0 return 0

using namespace std;

bool correctness (int a, int b, int c)
{
    bool res = 1;
    if(a + b <= c) res = 0;
    if(a + c <= b) res = 0;
    if(b + c <= a) res = 0;
    return res;
}

bool right(int a, int b, int c)
{
    bool res = 0;
    if(c*c == a*a + b*b) res = 1;
    if(b*b == a*a + c*c) res = 1;
    if(a*a == b*b + c*c) res = 1;
    return res;
}

find_left_index (int *ar, int l, int r, float A)
{
    if(r == l) return l;
    int m = (l + r) / 2;
    if(float(ar[m]) < A)
    {
        return find_left_index(ar, m + 1, r, A);
    }
    else
    {
        return find_left_index(ar, l, m, A);
    }
}

find_right_index (int *ar, int l, int r, float A)
{
    if(r <= l + 1) return l;
    int m = (l + r) / 2;
    if(float(ar[m]) > A)
    {
        return find_right_index(ar, l, m - 1, A);
    }
    else
    {
        return find_right_index(ar, m, r, A);
    }
}

signed main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int ar_len;

    cout << "Enter length of array : " << endl;
    cin >> ar_len;

    int* ar = new int [ar_len];

    cout << "Enter the array : " << endl;
    for(int i = 0; i < ar_len; i++)
        cin >> ar[i];

    sort(ar, ar + ar_len);

    set<set<int>> s;

    for(int i = 0; i < ar_len; i++)
    {
        for(int j = i + 1; j < ar_len; j++)
        {
            if(i == j) continue;

            int a = ar[i], b = ar[j];

            int l_ind = find_left_index(ar, 0, ar_len, sqrt(b*b - a*a));

            int r_ind = find_right_index(ar, 0, ar_len, sqrt(a*a + b*b));

            for(int k = l_ind; k <= r_ind; k++)
            {
                if(k == j or k == i) continue;
                if(correctness(a, b, ar[k]) and right(a, b, ar[k]))
                s.insert({a, b, ar[k]});
            }

        }
    }


    for(set <int> tr : s)
    {
        cout<<*(tr.begin()) << ' ' << *(next(tr.begin())) << ' ' << *(prev(tr.end())) << endl;
    }

    return 0;
}
