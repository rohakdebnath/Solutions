#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

bool isPrime(int n)
{
    bool survive = true;
    for (int i {2}; i*i <= n; ++i)
    {
        if (n % i == 0)
        {
            survive = false;
            break;
        }
    }
    return survive;
}

int lowestFactor(int n)
{
    for (int i {2}; i*i <= n; ++i)
    {
        if (n % i == 0) return i;
    }
    return n;
}

void solve()
{
    int l, r;
    cin >> l >> r;

    if ((l==1 and r == 2) or (l==1 and r==3) or (l==2 and r==3))
    {
        cout << -1 << '\n';
        return;
    }

    if (l == r)
    {
        if (isPrime(l)) 
        {
            cout << -1 << '\n';
            return;
        }
        else
        {
            cout << lowestFactor(l) << ' ' << l - lowestFactor(l) << '\n';
            return;
        }
    }

    for (int i {l}; i <= r; ++i)
    {
        if (i % 2 != 0 or i == 2) continue;
        cout << 2 << ' ' << i - 2 << '\n';
        break;
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }

    return 0;
}
