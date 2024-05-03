#include <bits/stdc++.h>
#define INF 1001007000
#define ooo 5223372036854775807
#define endl "\n"
#define r0 return 0
#define time_taken 1.0 * clock() / CLOCKS_PER_SEC

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

signed main()
{

    int n, k;

    cin >> n >> k;

    int len = (int) sqrt(n + 0.0);
    int bl_cnt = (int)ceil(n/len + 0.0);

    int *arr = new int [n];
    int *block = new int[bl_cnt];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(i < bl_cnt) block[i] = INF;
    }

    for(int i = 0; i < n; i++)
    {
        int idx = i/len;
        if(arr[i] < block[idx])
            block[idx] = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(i + k <= n)
        {
            int l = i, r = i + k - 1;

            int numBL = l/len;
            int numBR = r/len;

            if(numBL == numBR)
            {
                int mn = INF;
                for(int j = l; j <= r; j++)
                {
                    mn = min(mn, arr[j]);
                }
                printf("%d ", mn);
            }
            else
            {
                int mn = INF;
                for(int j = numBL + 1; j <= numBR - 1; j++)
                {
                    mn = min(mn, block[j]);
                }
                for(int j = l; j < (numBL + 1) * len; j++)
                {
                    mn = min(mn, arr[j]);
                }
                for(int j = numBR * len; j <= r; j++)
                {
                    mn = min(mn, arr[j]);
                }
                printf("%d ", mn);
            }
        }
    }

    printf("\n");

    delete [] arr;
    delete [] block;

    arr = nullptr;
    block = nullptr;

    return 0;
}

//https://informatics.msk.ru/mod/statements/view.php?id=20502#1
