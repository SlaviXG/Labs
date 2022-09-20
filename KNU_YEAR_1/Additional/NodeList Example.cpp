#include <bits/stdc++.h>
#define r0 return 0
#define time_taken 1.0 * clock() / CLOCKS_PER_SEC

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

typedef struct Node
{   int val;
    Node *next;
}   Listn, *Listp;

Listp lform (int);
void lprint (Listp);
int lcount (Listp);
void lreverse (Listp&);
Listp lfind (const Listp, int);

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n;

    cin >> n;
    cout << "\n";

    // creating
    Listp pbeg = lform(n);

    // printing
    lprint(pbeg);

    // counting elements
    cout << "Size of list is : " << lcount(pbeg) << "\n";

    // reversing
    lreverse(pbeg);

    // printing again
    lprint(pbeg);

    int k;
    cout << "Please, insert key : " << endl;
    cin >> k;

    Listp pk = lfind(pbeg, k);
    cout << ((pk) ? to_string(pk->val) : "Not found.") << "\n";

    return 0;
}

Listp lform(int n)
{
    Listp p, t = nullptr;
    for(int i = 1; i <= n; i++)
    {
        p = new Node;
        p->next = t;
        p->val = i;
        t = p;
    }
    cout << "List is created. \n";
    // n n-1 n-2 ... 1
    return p;
}

void lprint (Listp beg)
{
    cout << "List : ";
    Listp p = beg;
    while(p != nullptr)
    {
        cout << p->val << ' ';
        p = p-> next;
    }
    cout << "\n";
}

int lcount (Listp beg)
{
    int cnt = 0;
    Listp p = beg;
    while(p != nullptr)
    {
        cnt++;
        p = p-> next;
    }
    return cnt;
}

void lreverse(Listp &beg)
{
    Listp p = beg, prv = nullptr, t = nullptr, cur = nullptr;
    while(p != nullptr)
    {
        cur = p;
        t = p->next;
        p->next = prv;
        prv = cur;
        p = t;
    }
    beg = cur;
    cout << "List was reversed. \n";
}

Listp lfind(const Listp beg, int key)
{
    Listp p = beg;
    while(p != nullptr)
    {
        if(p->val == key) return p;
        p = p->next;
    }
    return nullptr;
}
