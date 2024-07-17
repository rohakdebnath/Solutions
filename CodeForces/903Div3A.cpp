#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

void solve()
{
    int n, m;
    cin >> n >> m;

    string x, s;
    cin >> x >> s;

    int ops {0};

    if (x == s)
    {
        cout << 0 << '\n';
        return;
    }
    
    while (x.size() < s.size())
    {
        x += x;
        ++ops;
    }

    for (int i {0}; i <= x.size() - s.size(); ++i)
    {
        if (x.substr(i, s.size()) == s)
        {
            cout << ops << '\n';
            return;
        }
    }
    ++ops;
    x +=x;

    for (int i {0}; i <= x.size() - s.size(); ++i)
    {
        if (x.substr(i, s.size()) == s)
        {
            cout << ops << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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
