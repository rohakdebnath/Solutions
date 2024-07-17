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
    i64 a, b, c;
    cin >> a >> b >> c;
    i64 minNum {min({a, b, c})};

    vector<i64> ordered {a, b, c};
    sort(all(ordered)); 

    if (a == b and b == c and c == a) cout << "YES\n";
    else if (!(ordered[2] % ordered[0] == 0 and ordered[1] % ordered[0] == 0)) cout << "NO\n";
    else
    {
        if (a/minNum + b/minNum + c/minNum - 3 > 3) cout << "NO\n";
        else cout << "YES\n";
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
