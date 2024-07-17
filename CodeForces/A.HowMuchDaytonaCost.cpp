#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<int>((x).size())
#define all(x) x.begin(), x.end()

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> list(n);
    for (int i {0}; i < n; ++i)
    {
        cin >> list[i];
    }

    bool found {false};

    for (int i : list)
    {
        if (k == i) found = true;
    }

    if (found) cout << "YES" << '\n';
    else cout << "NO" <<'\n';
}

int main()
{
    Unsync
    int tests;
    cin >> tests;

    while (tests--)
    {
        solve();
    }

    return 0;
}
