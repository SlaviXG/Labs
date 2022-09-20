#include <bits/stdc++.h>
#define r0 return 0

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

// 5 5 2 1 2 3 1 1 1

void pass_the_path (int *ar[], const int n, const int m, int rook_pos_x, int rook_pos_y, bool axis, int step_number)
{
    if(step_number < 0) return;

    if(ar[rook_pos_x][rook_pos_y] != 3)
    ar[rook_pos_x][rook_pos_y] = 1;
    step_number--;

    /// i - n - row - x; j - m - col - y

    if(axis)
    {
        for(int i = rook_pos_x + 1; i < n; i++)
        {
            if(ar[i][rook_pos_y] == 2) break;
            pass_the_path(ar, n, m, i, rook_pos_y, false, step_number);
        }

        for(int i = rook_pos_x - 1; i >= 0; i--)
        {
            if(ar[i][rook_pos_y] == 2) break;
            pass_the_path(ar, n, m, i, rook_pos_y, false, step_number);
        }
    }
    else
    {
        for(int j = rook_pos_y + 1; j < m; j++)
        {
            if(ar[rook_pos_x][j] == 2) break;
            pass_the_path(ar, n, m, rook_pos_x, j, true, step_number);
        }

        for(int j = rook_pos_y - 1; j >= 0; j--)
        {
            if(ar[rook_pos_x][j] == 2) break;
            pass_the_path(ar, n, m, rook_pos_x, j, true, step_number);
        }
    }

}

void print_array (int *ar[], int &n, int &m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << ar[i][j] << ' ';
        }
        cout << endl;
    }
}

signed main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, m, k;

    cout << "Enter a size of the board : n, m" << endl;
    cin >> n >> m;
    cout << "Enter a number of busy cells" << endl;
    cin >> k;

    int **ar = new int *[n];

    for(int i = 0; i < n; i++)
        ar[i] = new int [m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ar[i][j] = 0;

    int x, y;

    if(k)
    cout << "Enter the coordinates of busy cells :" << endl;
    while(k--)
    {
        cin >> x >> y;
        ar[--x][--y] = 2;
    }

    cout << "Enter the Rook position : x, y" << endl;
    cin >> x >> y;
    x--;y--;

    ar[x][y] = 3;

    pass_the_path(ar, n, m, x, y, true, 3);
    pass_the_path(ar, n, m, x, y, false, 3);

    print_array(ar, n, m);

    for(int i = 0; i < n; i++)
        delete [] ar[i];

    delete [] ar;

    return 0;
}

