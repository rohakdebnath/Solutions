#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

void towerRec(int n, int base, int target)
{
    if (n == 1)
    {
        cout << base << ' ' << target << '\n';
        return;
    }

    int other = 6 - base - target;
    towerRec(n - 1, base, other);
    cout << base << ' ' << target << '\n';
    towerRec(n - 1, other, target); 
}

int main()
{
    int n;
    cin >> n;

    cout << pow(2, n) - 1 << '\n';
    towerRec(n, 1, 3);
    return 0;
}
