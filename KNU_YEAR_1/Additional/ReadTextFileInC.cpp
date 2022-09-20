#include <bits/stdc++.h>
#define endl "\n"
#define r0 return 0

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

std :: string ReadTextFileInC (const char name [])
{
    std :: string Input = "";
    char c;
    FILE *file;
    file = fopen(name, "r");
    if (file)
    {
        while ((c = getc(file)) != EOF)
        Input+=c;
        fclose(file);
    }
    return Input;
}

signed main()
{

    std :: string s = ReadTextFileInC("test.txt");
    cout << s << endl;

    return 0;
}
